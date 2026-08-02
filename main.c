#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

#include "utils/pigeon_utils.h"

#define FB_COUNT 3

static int frameIdx = 0;

#define ACTOR_COUNT 3


// Import the model + create a draw block for it
// rspq_block_t* setupModel (const char *modelPath) {
//   T3DModel *model = t3d_model_load(modelPath);
//   rspq_block_t *envDPL = NULL;

//   rspq_block_begin();
//   t3d_model_draw(model);
//   envDPL = rspq_block_end();
//   return envDPL;
// }

int main()
{
	debug_init_isviewer();
  debug_init_usblog();
  asset_init_compression(2);

  dfs_init(DFS_DEFAULT_LOCATION);

  display_init(RESOLUTION_320x240, DEPTH_16_BPP, FB_COUNT, GAMMA_NONE, FILTERS_RESAMPLE_ANTIALIAS);

  rdpq_init();

  t3d_init((T3DInitParams){});
  joypad_init();

  T3DViewport viewport = t3d_viewport_create_buffered(FB_COUNT);

  fm_vec3_t camPos = {{ 0, 100.0f, 40.0f }};
  fm_vec3_t camTarget = {{0,100.0f,0}};

  uint8_t colorAmbient[4] = {69, 69, 69, 0x22};
  uint8_t colorDir[4]     = {0xFF, 0xFF, 0xFF, 0x22};

  fm_vec3_t lightDirVec = {{-1.0f, 1.0f, 1.0f}};
  fm_vec3_norm(&lightDirVec, &lightDirVec);

  // SETUP ENVIRONMENT
  // you basically need 1 model import and 1 DPL per model
  rspq_block_t *groundDPL = setupModel("rom:/ground.t3dm");
  rspq_block_t *stumpDPL = setupModel("rom:/stump.t3dm");


  Actor actors[ACTOR_COUNT] = {
    setupActor(0, groundDPL, (float[3]){0,0,0}, (float[3]){0,0,0}, (float[3]){0.5f,0.5f,0.5f}, FB_COUNT),
    setupActor(1, stumpDPL, (float[3]){-200.0f,0,-50.0f}, (float[3]){0,-45.0f,0}, (float[3]){0.5f,0.5f,0.5f}, FB_COUNT),
    setupActor(2, stumpDPL, (float[3]){100.0f, 0, 50.0f}, (float[3]){0,90.0f,0}, (float[3]){0.5f,0.5f,0.5f}, FB_COUNT),
  };

  for(;;) {
    // UPDATE
    frameIdx = (frameIdx + 1) % FB_COUNT;

    joypad_poll();
    joypad_inputs_t input = joypad_get_inputs(0);

    float xInput = 0.0f;
    float yInput = 0.0f;  
    if (input.stick_x > 0) {
      xInput = 1.00f;
    } else if (input.stick_x < 0) {
      xInput = -1.00f;
    }
    if (input.stick_y > 0) {
      yInput = 1.0f;
    }else if (input.stick_y < 0) {
      yInput = -1.0f;
    }

    fm_vec3_t inputVector = {{ xInput, yInput, 0.0f }};

    fm_vec3_norm(&inputVector, &inputVector);

    camPos.z -= inputVector.y * 5;
    camPos.x += inputVector.x * 5;
    camTarget.x = camPos.x;
    camTarget.y = 100.0f;
    camTarget.z = camPos.z - 10.0f;
    

    // Apply actor's settings
    for(int i=0; i<ACTOR_COUNT; ++i) {
      t3d_mat4fp_from_srt_euler(&actors[i].modelMat[frameIdx], actors[i].scale, actors[i].rot, actors[i].pos);
    }

    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(85.0f), 10.0f, 250.0f);
    t3d_viewport_look_at(&viewport, &camPos, &camTarget, &(fm_vec3_t){{0,1,0}});

    // DRAW
    rdpq_attach(display_get(), display_get_zbuf());
    t3d_frame_start();
    t3d_viewport_attach(&viewport);

    // rdpq_set_prim_color(RGBA32(0, 0, 0, 0xFF));

    t3d_screen_clear_color(RGBA32(100, 80, 80, 0xFF)); // clears the screen 
    t3d_screen_clear_depth(); // clears the depth buffer

    t3d_light_set_ambient(colorAmbient);
    t3d_light_set_directional(0, colorDir, &lightDirVec);
    t3d_light_set_count(1); // 0-7 lights in addition to the ambient light

    // we say we'd like to take a "single" matrix
    t3d_matrix_push_pos(1);
    for(int i=0; i<ACTOR_COUNT; ++i) {
      // actor_draw(&actors[i]);
      // we set a matrix (the model's material / transform + dpl) with doMultiply as true, it just push+pops it by itself
      t3d_matrix_set(&actors[i].modelMat[frameIdx], true);
      rspq_block_run(actors[i].dpl);
    }
    // we then pop a "singular" matrix
    t3d_matrix_pop(1);

    rdpq_detach_show();
  }

  t3d_destroy();
  return 0;
}
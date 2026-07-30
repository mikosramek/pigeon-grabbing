#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

#define FB_COUNT 3

static int frameIdx = 0;
static int handSpeed = 5;

typedef struct {
  uint32_t id;
  float pos[3];
  float rot[3];
  float scale[3];

  rspq_block_t *dpl;
  T3DMat4FP *modelMat;
} Actor;


Actor createActor(uint32_t id, rspq_block_t *dpl, float *position) {
  float scale = 0.6f;
  Actor newHand = (Actor) {
    .id = id,
    .rot = {-45.0f, 0, 0},
    .scale = {scale, scale, scale},
    .dpl = dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * FB_COUNT)
  };

  newHand.pos[0] = position[0];
  newHand.pos[1] = position[1];
  newHand.pos[2] = position[2];

  return newHand;
}


void updateHand (Actor *hand, fm_vec3_t inputVector, fm_vec3_t newRot) {
  hand->pos[0] += inputVector.x * handSpeed;
  hand->pos[1] += inputVector.y * handSpeed;
  hand->rot[0] = newRot.x;
  hand->rot[1] = newRot.y;
  hand->rot[2] = newRot.z;
  t3d_mat4fp_from_srt_euler(&hand->modelMat[frameIdx], hand->scale, hand->rot, hand->pos);
}

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

  T3DModel *hand = t3d_model_load("rom:/hand.t3dm");

  rspq_block_t *rightHandDraw = NULL;
  Actor hands = createActor(0, rightHandDraw, (float[3]){0.0f, 40.0f, -50.0f});

  fm_vec3_t handRot = {{ -45.0f, 0, 0 }};

  // SETUP ENVIRONMENT
  T3DModel *ground = t3d_model_load("rom:/ground.t3dm");
  T3DMat4FP* groundMatFP = malloc_uncached(sizeof(T3DMat4) * FB_COUNT);

  T3DModel *stump = t3d_model_load("rom:/stump.t3dm");
  // T3DModel *stump2 = t3d_model_load("rom:/stump.t3dm");
  T3DMat4FP* stumpMatFP = malloc_uncached(sizeof(T3DMat4) * FB_COUNT);
  T3DMat4FP* stumpMatFP2 = malloc_uncached(sizeof(T3DMat4) * FB_COUNT);

  rspq_block_t *parkSceneDrawBlock = NULL;
  rspq_block_t *stumpDrawBlock = NULL;

  for(;;) {
    // UPDATE
    frameIdx = (frameIdx + 1) % FB_COUNT;

    // camPos.z += 0.01f;

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
    

    if (input.cstick_y > 0) {
      handRot.x -= 0.02f;
    } else if (input.cstick_y < 0) {
      handRot.x += 0.02f;
    }

    if (input.cstick_x > 0) {
      handRot.y += 0.02f;
    } else if (input.cstick_x < 0) {
      handRot.y -= 0.02f;
    }

    // updateHand(&hands, inputVector, handRot);
    t3d_mat4fp_from_srt_euler(
      groundMatFP,
      (float[3]){0.5f, 0.5f, 0.5f},
      (float[3]){0.0f, 0.0f, 0.0f},
      (float[3]){0.0f, 0.0f, -250.0f}
    );
    t3d_mat4fp_from_srt_euler(
      stumpMatFP,
      (float[3]){1.0f, 1.0f, 1.0f},
      (float[3]){0.0f, -90.0f, 0.0f},
      (float[3]){500.0f, 0.0f, -250.0f}
    );
    t3d_mat4fp_from_srt_euler(
      stumpMatFP2,
      (float[3]){0.5f, 0.5f, 0.5f},
      (float[3]){0.0f, 45.0f, 0.0f},
      (float[3]){-100.0f, 0.0f, -250.0f}
    );

    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(85.0f), 10.0f, 250.0f);
    t3d_viewport_look_at(&viewport, &camPos, &camTarget, &(fm_vec3_t){{0,1,0}});

    t3d_mat4fp_from_srt_euler(&hands.modelMat[frameIdx],
      hands.scale,
      hands.rot,
      hands.pos
    );

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


    // setup hand draw block
    if (!hands.dpl) {
      rspq_block_begin();
      t3d_model_draw(hand);
      t3d_matrix_pop(1);

      hands.dpl = rspq_block_end();
    }

    if (!parkSceneDrawBlock) {
      rspq_block_begin();

      // t3d_model_draw(stump);
      // t3d_model_draw(stump2);
      t3d_model_draw(ground);
      t3d_matrix_pop(1);

      parkSceneDrawBlock = rspq_block_end();
    }

    if (!stumpDrawBlock) {
      rspq_block_begin();
      t3d_model_draw(stump);
      t3d_model_draw(stump);
      t3d_matrix_pop(2);
      stumpDrawBlock = rspq_block_end();
    }

    t3d_matrix_push(
      hands.modelMat);
    rspq_block_run(hands.dpl);

    t3d_matrix_push(groundMatFP);
    rspq_block_run(parkSceneDrawBlock);
    t3d_matrix_push(stumpMatFP);
    t3d_matrix_push(stumpMatFP2);

    rspq_block_run(stumpDrawBlock);

    rdpq_detach_show();
  }

  t3d_destroy();
  return 0;
}
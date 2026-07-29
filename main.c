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
} Hand;


Hand createHand(uint32_t id, rspq_block_t *dpl, float xOffset) {
  Hand newHand = (Hand) {
    .id = id,
    .pos = {xOffset, 0, -100.0f},
    .rot = {-45.0f, 0, 0},
    .scale = {1.0f, 1.0f, 1.0f},
    .dpl = dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * FB_COUNT)
  };
  return newHand;
}

void updateHand (Hand *hand, fm_vec3_t inputVector, fm_vec3_t newRot) {
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

  const fm_vec3_t camPos = {{ 0, 10.0f, 40.0f }};
  const fm_vec3_t camTarget = {{0,0,0}};

  uint8_t colorAmbient[4] = {80, 80, 100, 0xFF};
  uint8_t colorDir[4]     = {0xEE, 0xAA, 0xAA, 0xFF};

  fm_vec3_t lightDirVec = {{-1.0f, 1.0f, 1.0f}};
  fm_vec3_norm(&lightDirVec, &lightDirVec);

  T3DModel *hand = t3d_model_load("rom:/hand.t3dm");

  rspq_block_t *rightHandDraw = NULL;
  Hand hands = createHand(0, rightHandDraw, 50.0f);

  fm_vec3_t handRot = {{ -45.0f, 0, 0 }};

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

    updateHand(&hands, inputVector, handRot);

    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(85.0f), 10.0f, 150.0f);
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

    t3d_matrix_push(
      hands.modelMat);
    rspq_block_run(hands.dpl);

    rdpq_detach_show();
  }

  t3d_destroy();
  return 0;
}
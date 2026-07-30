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

typedef struct {
  uint32_t id;
  Actor *actors;
} Scene;

#define ACTOR_COUNT 3


Actor createActor(uint32_t id, rspq_block_t *dpl, float *scale, float *rot, float *position) {
  Actor newActor = (Actor) {
    .id = id,
    .dpl = dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * FB_COUNT)
  };

  newActor.pos[0] = position[0];
  newActor.pos[1] = position[1];
  newActor.pos[2] = position[2];

  newActor.rot[0] = rot[0];
  newActor.rot[1] = rot[1];
  newActor.rot[2] = rot[2];

  newActor.scale[0] = scale[0];
  newActor.scale[1] = scale[1];
  newActor.scale[2] = scale[2];

  return newActor;
}


void updateHand (Actor *hand, fm_vec3_t inputVector, fm_vec3_t newRot) {
  hand->pos[0] += inputVector.x * handSpeed;
  hand->pos[1] += inputVector.y * handSpeed;
  hand->rot[0] = newRot.x;
  hand->rot[1] = newRot.y;
  hand->rot[2] = newRot.z;
  t3d_mat4fp_from_srt_euler(&hand->modelMat[frameIdx], hand->scale, hand->rot, hand->pos);
}

// init actors
/*

INIT
  rspq_block_t *dpls[2];
  T3DModel *models[2] = {
    t3d_model_load("rom:/box.t3dm"),
    t3d_model_load("rom:/food.t3dm")
  };

  for(int i=0; i<2; ++i) {
    rspq_block_begin();
    t3d_model_draw(models[i]);
    dpls[i] = rspq_block_end();
  }

  Actor actors[ACTOR_COUNT];
  for(int i=0; i<ACTOR_COUNT; ++i) {
    actors[i] = actor_create(i, dpls[i*3 % 2]);
  }

LOOP
  for(int i=0; i<actorCount; ++i) {
    actor_update(&actors[i]);
    //   t3d_mat4fp_from_srt_euler(&actor->modelMat[frameIdx], actor->scale, actor->rot, actor->pos);
  }


  t3d_matrix_push_pos(1);
  for(int i=0; i<actorCount; ++i) {
    actor_draw(&actors[i]);
    // t3d_matrix_set(&actor->modelMat[frameIdx], true);
    // rspq_block_run(actor->dpl);
  }
  t3d_matrix_pop(1);

*/

// Scene initPark(void) {
//   Actor items[3];
//   items[0] = (Actor){
//     .id = 0,
//     .dpl
//   };
//   Scene Park = (Scene) {
//     .id = 1,
//     .actors = items
//   };

//   return Park;
// }

// void drawScene(void) {

// }

// Import the model + create a draw block for it
rspq_block_t* setupModel (const char *modelPath) {
  T3DModel *model = t3d_model_load(modelPath);
  rspq_block_t *envDPL = NULL;

  rspq_block_begin();
  t3d_model_draw(model);
  envDPL = rspq_block_end();
  return envDPL;
}

// create an Actor struct, applying base pos/rot/scale + draw block and model material
Actor setupActor(uint32_t id, rspq_block_t *dpl, const float pos[3], const float rot[3], const float scale[3]) {
  Actor actor = (Actor) {
    .id = id,
    .pos = {pos[0], pos[1], pos[2]},
    .rot = {rot[0], rot[1], rot[2]},
    .scale = {scale[0], scale[1], scale[2]},
    .dpl = dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * FB_COUNT)
  };
  return actor;
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

  // T3DModel *hand = t3d_model_load("rom:/hand.t3dm");

  // rspq_block_t *rightHandDraw = NULL;
  // Actor hands = createActor(0, rightHandDraw, (float[3]){0.0f, 40.0f, -50.0f});

  // fm_vec3_t handRot = {{ -45.0f, 0, 0 }};

  // SETUP ENVIRONMENT
  // you basically need 1 model import and 1 DPL per model
  rspq_block_t *groundDPL = setupModel("rom:/ground.t3dm");
  rspq_block_t *stumpDPL = setupModel("rom:/stump.t3dm");


  Actor actors[ACTOR_COUNT] = {
    setupActor(0, groundDPL, (float[3]){0,0,0}, (float[3]){0,0,0}, (float[3]){0.5f,0.5f,0.5f}),
    setupActor(1, stumpDPL, (float[3]){-200.0f,0,-50.0f}, (float[3]){0,-45.0f,0}, (float[3]){0.5f,0.5f,0.5f}),
    setupActor(2, stumpDPL, (float[3]){100.0f, 0, 50.0f}, (float[3]){0,90.0f,0}, (float[3]){0.5f,0.5f,0.5f}),
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
    

    // if (input.cstick_y > 0) {
    //   handRot.x -= 0.02f;
    // } else if (input.cstick_y < 0) {
    //   handRot.x += 0.02f;
    // }

    // if (input.cstick_x > 0) {
    //   handRot.y += 0.02f;
    // } else if (input.cstick_x < 0) {
    //   handRot.y -= 0.02f;
    // }

    // updateHand(&hands, inputVector, handRot);

    // Apply actor's settings
    for(int i=0; i<ACTOR_COUNT; ++i) {
      t3d_mat4fp_from_srt_euler(&actors[i].modelMat[frameIdx], actors[i].scale, actors[i].rot, actors[i].pos);
    }

    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(85.0f), 10.0f, 250.0f);
    t3d_viewport_look_at(&viewport, &camPos, &camTarget, &(fm_vec3_t){{0,1,0}});

    // t3d_mat4fp_from_srt_euler(&hands.modelMat[frameIdx],
    //   hands.scale,
    //   hands.rot,
    //   hands.pos
    // );

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
    // if (!hands.dpl) {
    //   rspq_block_begin();
    //   t3d_model_draw(hand);
    //   t3d_matrix_pop(1);

    //   hands.dpl = rspq_block_end();
    // }

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
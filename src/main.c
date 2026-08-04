#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>
#include <math.h>

#include "utils/pigeon_utils.h"
#include "utils/pigeon_math.h"

// SCENES
#include "scenes/scene.h"
#include "scenes/park.h"
#include "scenes/hedges.h"
#include "scenes/pond.h"

#define FB_COUNT 3

static int frameIdx = 0;


static Scene currentScene;
#define SCENE_COUNT 3

void changeScene (int sceneId) {
  rspq_wait();

  // unload current scene
  switch(currentScene.id) {
    case 0:
      unloadPark();
      break;
    case 1:
      unloadHedges();
      break;
    case 2:
      unloadPond();
      break;
    default:
      assertf(false, "Current scene doesn't have an unload: %d", (int)currentScene.id);
  }

  switch(sceneId) {
    case 0:
      currentScene = createPark(FB_COUNT, 0);
      break;
    case 1:
      currentScene = createHedges(FB_COUNT, 1);
      break;
    case 2:
      currentScene = createPond(FB_COUNT, 2);
      break;
    default:
      assertf(false, "Invalid scene-id: %d", sceneId);
  }
};

int main()
{
	debug_init_isviewer();
  debug_init_usblog();
  asset_init_compression(2);

  dfs_init(DFS_DEFAULT_LOCATION);

  display_init(RESOLUTION_320x240, DEPTH_16_BPP, FB_COUNT, GAMMA_NONE, FILTERS_RESAMPLE_ANTIALIAS);

  rdpq_init();
  t3d_init((T3DInitParams){});

  // camera controls
  float cameraY = 20.0f;
  float cameraAngle = -M_PI / 2;
  uint32_t movementSpeed = 2;
  float cameraRotationSpeed = 0.05f;
  joypad_init();

  T3DViewport viewport = t3d_viewport_create_buffered(FB_COUNT);

  // rendering distance
  float cam_near = 10.0f;
  float cam_far = 250.0f;

  fm_vec3_t camPos = {{ 0, cameraY, 40.0f }};
  fm_vec3_t camTarget = {{0,cameraY,0}};

  uint8_t colorAmbient[4] = {69, 69, 69, 0x22};
  uint8_t colorDir[4]     = {0xFF, 0xFF, 0xFF, 0x22};
  // color_t fogColor = (color_t){140, 50, 20, 0xFF};

  fm_vec3_t lightDirVec = {{-1.0f, 1.0f, 1.0f}};
  fm_vec3_norm(&lightDirVec, &lightDirVec);

  // Scene park = createPark(FB_COUNT, 1);
  // Scene hedges = createHedges(FB_COUNT, 2);
  // currentScene = park;
  currentScene = createPark(FB_COUNT, 0);

  rdpq_text_register_font(FONT_BUILTIN_DEBUG_MONO, rdpq_font_load_builtin(FONT_BUILTIN_DEBUG_MONO));


  for(;;) {
    // UPDATE
    frameIdx = (frameIdx + 1) % FB_COUNT;

    joypad_poll();
    joypad_inputs_t input = joypad_get_inputs(0);


    // MOVEMENT INPUTS
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

    // CAMERA INPUTS
    if (input.cstick_x > 0) {
      cameraAngle += 1.0f * cameraRotationSpeed;
    } else if (input.cstick_x < 0) {
      cameraAngle -= 1.0f * cameraRotationSpeed;
    }
    cameraAngle = fmod(cameraAngle, M_PI * 2.0f);

    if (input.cstick_y > 0) {
      cameraY -= 0.5f * cameraRotationSpeed;
    } else if (input.cstick_y < 0) {
      cameraY += 0.5f * cameraRotationSpeed;
    }
    cameraY = clamp(cameraY, 19.0f, 20.6f);

    // get forward angle
    float xTarget = cos(cameraAngle);
    float zTarget = sin(cameraAngle);

    // get perpendicular angle
    float perpXTarget = cos(cameraAngle + M_PI / 2.0f);
    float perpZTarget = sin(cameraAngle + M_PI / 2.0f);

    // UPDATE CAMERA

    // combine forward/back input + forward angle AND left/right input + perp angle
    float zChange = (inputVector.y * zTarget * movementSpeed) + (inputVector.x * perpZTarget * movementSpeed);
    float xChange = (inputVector.y * xTarget * movementSpeed) + (inputVector.x * perpXTarget * movementSpeed);

    // normalize input, so angular movement isn't doubled
    fm_vec3_t posChange = {{ xChange, 0, zChange }};
    fm_vec3_norm(&posChange, &posChange);
    
    // apply position
    camPos.z += posChange.z;
    camPos.x += posChange.x;

    // apply camera target
    camTarget.x = camPos.x + xTarget;
    camTarget.y = cameraY;
    camTarget.z = camPos.z + zTarget;
    
    // Apply actor's settings
    Actor* actors = currentScene.actors;
    for(int i=0; i<currentScene.actorCount; ++i) {
      t3d_mat4fp_from_srt_euler(&actors[i].modelMat[frameIdx], actors[i].scale, actors[i].rot, actors[i].pos);
    }

    // set camera
    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(85.0f), cam_near, cam_far);
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

    // fog settings
    // rdpq_mode_fog(RDPQ_FOG_STANDARD);
    // rdpq_set_fog_color(fogColor);

    // t3d_fog_set_range(-20.0f, 50.0f);
    // t3d_fog_set_enabled(true);

    // we say we'd like to take a "single" matrix
    t3d_matrix_push_pos(1);
    for(int i=0; i<currentScene.actorCount; ++i) {
      // actor_draw(&actors[i]);
      // we set a matrix (the model's material / transform + dpl) with doMultiply as true, it just push+pops it by itself
      t3d_matrix_set(&actors[i].modelMat[frameIdx], true);
      rspq_block_run(actors[i].dpl);
    }
    // we then pop a "singular" matrix
    t3d_matrix_pop(1);

    // debug text
    // rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 210, "camera angle: %f", cameraAngle);
    // rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 220, "camera x: %f", cos(cameraAngle));
    // rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "camera z: %f", sin(cameraAngle));
    // rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "camera y: %f", cameraY);
    rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "current scene: %i", (int)currentScene.id);

    rdpq_detach_show();


    // SCENE CHANGE DEBUG
    joypad_buttons_t buttons = joypad_get_buttons_pressed(0);
    if (buttons.l) {
      if (currentScene.id > 0) {
        changeScene(currentScene.id - 1);
      } else {
        changeScene(SCENE_COUNT - 1);
      }
    } else if (buttons.r) {
      if (currentScene.id < SCENE_COUNT - 1) {
        changeScene(currentScene.id + 1);
      } else {
        changeScene(0);
      }
    }
  }

  unloadPark();

  t3d_destroy();
  return 0;
}
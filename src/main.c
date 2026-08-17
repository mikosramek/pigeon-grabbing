#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>
#include <math.h>

// STATE
#include "globals.h"
#include "state.h"

// PLAYER
#include "player/player.h"

// UTILS
#include "utils/pigeon_utils.h"
#include "utils/pigeon_math.h"
#include "utils/pigeon_audio.h"
#include "utils/pigeon_ui.h"
#include "entities/entity.h"

// SCENES
#include "sceneManager.h"
#include "scenes/scene.h"


static int frameIdx = 0;

static State state = {
  .activeScene = NULL,
  .requestSceneId = -1,
  .feathersCollected = 0,
};

State *getState(void)
{
    return &state;
}

static Debug DEBUG = {
  .debugEnabled = false,
  .infoMode = SCENE
};

void display_debug(void) {
  if (!DEBUG.debugEnabled) {
    return;
  }
  switch (DEBUG.infoMode) {
    case CAMERA:
      Player *player = getPlayer();
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 190, "camera y pos: %f", player->position.y);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 200, "camera rotation: %f", player->cameraAngle);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 210, "camera target: %f/%f/%f", cos(player->cameraAngle), sin(player->cameraAngle), player->cameraY);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 220, "fov: %f", player->cameraFOV);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "d_up/d_down: change FOV");
      break;
    case AUDIO:
      PigeonAudio *pigeonAudio = getPigeonAudio();
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 220, "tranquil walk playing: %s", pigeonAudio->tranquilWalk.playing ? "y" : "n");
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "c_up: play | c_down: stop");
      break;
    case SCENE:
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 210, "current scene name: %s", state.activeScene->name);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 220, "current scene id: %i", (int)state.activeScene->id);
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "c_right/c_left: scene change");
      break;
    case HIDDEN:
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 16, 230, "l/r: change info | start: disable debug");
      break;
    default:
      break;
  }
}

void handle_debug_input(SceneManager *sceneManager) {
  joypad_buttons_t buttons = joypad_get_buttons_pressed(1);
  joypad_buttons_t heldButtons = joypad_get_buttons(1);
  if (buttons.start) {
    DEBUG.debugEnabled = !DEBUG.debugEnabled;
  }

  if (!DEBUG.debugEnabled) {
    return;
  }

  if (buttons.l) {
    if (DEBUG.infoMode == CAMERA) {
      DEBUG.infoMode = HIDDEN;
    } else {
      DEBUG.infoMode = DEBUG.infoMode - 1;
    }
  }
  if (buttons.r) {
    if (DEBUG.infoMode == HIDDEN) {
      DEBUG.infoMode = 0;
    } else {
      DEBUG.infoMode = DEBUG.infoMode + 1;
    }
  }

  if (DEBUG.infoMode == SCENE) {
    State *state = getState();
    if (buttons.c_left) {
      if (state->activeScene->id > 0) {
        sceneManager->loadScene(state->activeScene->id - 1);
      } else {
        sceneManager->loadScene(sceneManager->sceneCount - 1);
      }
      resetPlayer();
    } else if (buttons.c_right) {
      if (state->activeScene->id < sceneManager->sceneCount - 1) {
        sceneManager->loadScene(state->activeScene->id + 1);
      } else {
        sceneManager->loadScene(0);
      }
      resetPlayer();
    }
  } else if (DEBUG.infoMode == AUDIO) {
    if (buttons.c_up) {
      p_audio_play_track(TRANQUIL_WALK);
    }
    if (buttons.c_down) {
      p_audio_stop_track(TRANQUIL_WALK);
    }
  } else if (DEBUG.infoMode == CAMERA) {
    Player *player = getPlayer();
    if (heldButtons.d_up) {
      player->cameraFOV += 0.5f;
    } else if (heldButtons.d_down) {
      player->cameraFOV -= 0.5f;
    }
  }
}

void handle_game_ui(void) {
  State *state = getState();
  int totalFeathers = 0;
  for(int i=0; i < state->activeScene->entityCount; ++i) {
    if (state->activeScene->entities[i].entityId == 0) {
      totalFeathers += 1;
    }
  }
  rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 290, 16, "%i/%i", state->feathersCollected, totalFeathers);
}

int main()
{
  // System Init
	debug_init_isviewer();
  debug_init_usblog();
  asset_init_compression(2);

  dfs_init(DFS_DEFAULT_LOCATION);

  display_init(RESOLUTION_320x240, DEPTH_16_BPP, FB_COUNT, GAMMA_NONE, FILTERS_RESAMPLE_ANTIALIAS);

  rdpq_init();
  t3d_init((T3DInitParams){});
  joypad_init();
  T3DViewport viewport = t3d_viewport_create_buffered(FB_COUNT);

  // Game Init
  ui_init_sprites();
  p_audio_init();
  // empty, sunflower, safflower
  bool inventory[3] = { true, true, false };
  player_init(inventory);
  SceneManager* sceneManager = scene_manager_create(1);
  Player *player = getPlayer();


  // Rendering Setup
  // rendering distance
  float cam_near = 5.0f;
  float cam_far = 250.0f;

  // basic lighting
  uint8_t colorAmbient[4] = {69, 69, 69, 0x22};
  uint8_t colorDir[4]     = {0xFF, 0xFF, 0xFF, 0x22};
  color_t fogColor = (color_t){0x87, 0xCE, 0xEB, 0xff};

  fm_vec3_t lightDirVec = {{-1.0f, 1.0f, 1.0f}};
  fm_vec3_norm(&lightDirVec, &lightDirVec);

  rdpq_text_register_font(FONT_BUILTIN_DEBUG_MONO, rdpq_font_load_builtin(FONT_BUILTIN_DEBUG_MONO));

  p_audio_play_track(TRANQUIL_WALK);

  uint32_t time = 0;

  for(;;) {
    // UPDATE
    time += 1;
    sceneManager->update();
    frameIdx = (frameIdx + 1) % FB_COUNT;

    joypad_poll();
    player_update();
    player_handle_entities();
    for (int i = 0; i < 3; i += 1) {
      mixer_try_play();
    }
    
    State *state = getState();
    // Grab Actors from the current active scene + apply actor's settings
    Actor* actors = state->activeScene->actors;
    for(int i=0; i < state->activeScene->actorCount; ++i) {
      // t3d_mat4fp_from_srt_euler(&actors[i].modelMat[frameIdx], actors[i].scale, actors[i].rot, actors[i].pos);
      t3d_mat4fp_from_srt(&actors[i].modelMat[frameIdx], actors[i].scale, actors[i].rot, actors[i].pos);
    }

    struct Entity *entities = state->activeScene->entities;
    for(int i = 0; i < state->activeScene->entityCount; i++) {
      entities[i].update(&entities[i], time);
    }

    // set camera
    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(player->cameraFOV), cam_near, cam_far);
    t3d_viewport_look_at(&viewport, &player->position, &player->cameraTarget, &(fm_vec3_t){{0,1,0}});

    // DRAW
    surface_t *surface = display_get();
    rdpq_attach(surface, display_get_zbuf());
    t3d_frame_start();
    t3d_viewport_attach(&viewport);

    // rdpq_set_prim_color(RGBA32(0, 0, 0, 0xFF));

    t3d_screen_clear_color(fogColor); //RGBA32(100, 80, 80, 0xFF)); // clears the screen 
    t3d_screen_clear_depth(); // clears the depth buffer

    t3d_light_set_ambient(colorAmbient);
    t3d_light_set_directional(0, colorDir, &lightDirVec);
    t3d_light_set_count(1); // 0-7 lights in addition to the ambient light

    // fog settings
    // rdpq_mode_fog(RDPQ_FOG_STANDARD);
    // rdpq_set_fog_color(fogColor);
    // t3d_fog_set_enabled(true);
    // t3d_fog_set_range(25.0f, 50.0f);

    // we say we'd like to take a "single" matrix
    t3d_matrix_push_pos(1);
    for(int i=0; i < state->activeScene->actorCount; ++i) {
      // T3DFrustum fr = viewport.viewFrustum;
      // t3d_frustum_scale(&fr, 6.40f);
      bool isVisible = true; //t3d_frustum_vs_aabb_s16(&fr, actors[i].model->aabbMin, actors[i].model->aabbMax);
      // if (i == state->activeScene->actorCount - 2) {
      //   uint16_t *buff = (uint16_t*)surface->buffer;
      //   debugDrawAABB(buff, actors[i].model->aabbMin, actors[i].model->aabbMax, &viewport, 0.1f, 0x037f);
      // }
      if (!actors[i].skip && isVisible) {
        // actor_draw(&actors[i]);
        // we set a matrix (the model's material / transform + dpl) with doMultiply as true, it just push+pops it by itself
        t3d_matrix_set(&actors[i].modelMat[frameIdx], true);
        rspq_block_run(actors[i].dpl);
      }
    }
    // we then pop a "singular" matrix
    t3d_matrix_pop(1);

    // 2D THINGS
    rdpq_set_mode_standard();
    rdpq_mode_blender(RDPQ_BLENDER_MULTIPLY);
    player_draw_ui();
    handle_game_ui();
    display_debug();
    handle_debug_input(sceneManager);
    
    // end rendering
    rdpq_detach_show();
  
  }

  t3d_destroy();
  return 0;
}
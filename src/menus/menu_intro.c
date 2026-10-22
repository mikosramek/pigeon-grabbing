#include "menu_intro.h"
#include "libdragon.h"
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

#include "../globals.h"

int run_menu_intro(void) {

  T3DViewport viewport = t3d_viewport_create_buffered(FB_COUNT);

  float cam_near = 5.0f;
  float cam_far = 100.0f;

  fm_vec3_t camPos = {{ 0.0f, 0.0f, 0.0f }};
  fm_vec3_t camTarget = {{ 1.0f, 0.0f, 0.0f }};
  int frameIdx = 0;

  color_t bgColor = (color_t){0x33, 0xCE, 0xEB, 0xff};

  bool showIntro = true;
  uint32_t time = 0;
  while(showIntro) {
    frameIdx = (frameIdx + 1) % FB_COUNT;
    time += 1;

    
    t3d_viewport_set_projection(&viewport, T3D_DEG_TO_RAD(75), cam_near, cam_far);
    t3d_viewport_look_at(&viewport, &camPos, &camTarget, &(fm_vec3_t){{0,1,0}});
    
    rdpq_attach(display_get(), display_get_zbuf());
    t3d_frame_start();
    t3d_screen_clear_color(bgColor);
    t3d_screen_clear_depth(); // clears the depth buffer
    t3d_viewport_attach(&viewport);

    // t3d_light_set_ambient(colorAmbient);
    // t3d_light_set_directional(0, colorDir, &lightDirVec);
    // t3d_light_set_count(1); // 0-7 lights in addition to the ambient light
    

    // **** 3D ****
    // t3d_mat4fp_from_srt(&debugMats[frameIdx], (float[3]){ 0.1f, 0.1f, 0.1f}, (float[4]){0.0f, 0.0f , 0.0f, 0.0f}, state->debugPos);


    // t3d_matrix_push_pos(1);
    // t3d_matrix_set(&actors[i].modelMat[frameIdx], true);
    // rspq_block_run(actors[i].dpl);
    // for(int i=0; i < state->activeLevel->activeScene->actorCount; ++i) {
    //   bool isVisible = t3d_frustum_vs_aabb_s16(&fr, actors[i].worldMin, actors[i].worldMax);
    //   if (!actors[i].skip && isVisible) {
    //     // actor_draw(&actors[i]);
    //     // we set a matrix (the model's material / transform + dpl) with doMultiply as true, it just push+pops it by itself
    //     t3d_matrix_set(&actors[i].modelMat[frameIdx], true);
    //     rspq_block_run(actors[i].dpl);
    //   }
    // }
    // we then pop a "singular" matrix
    // t3d_matrix_pop(1);


    // **** 2D ****
    rdpq_set_mode_standard();
    rdpq_mode_blender(RDPQ_BLENDER_MULTIPLY);
    rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 230, 16, "fps: %f", display_get_fps());

    if (time < 120) {
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 140, 120, "N64");
    } else if (time >= 120 && time < 240) {
      rdpq_text_printf(NULL, FONT_BUILTIN_DEBUG_MONO, 140, 120, "libdragon");
    } else {
      showIntro = false;
    }

    rdpq_detach_show();
  }
  
  return 0;
}

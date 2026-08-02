#include "pigeon_utils.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

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
Actor setupActor(uint32_t id, rspq_block_t *dpl, const float pos[3], const float rot[3], const float scale[3], uint32_t fbCount) {
  Actor actor = (Actor) {
    .id = id,
    .pos = {pos[0], pos[1], pos[2]},
    .rot = {rot[0], rot[1], rot[2]},
    .scale = {scale[0], scale[1], scale[2]},
    .dpl = dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * fbCount)
  };
  return actor;
}
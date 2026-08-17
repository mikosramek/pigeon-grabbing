#include "pigeon_utils.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// Import the model + create a draw block for it
ModelData setupModel (const char *modelPath) {
  T3DModel *model = t3d_model_load(modelPath);

  rspq_block_begin();
  // rdpq_mode_alphacompare(10);
  t3d_model_draw(model);
  rspq_block_t *envDPL = rspq_block_end();

  return (ModelData) {
    .model = model,
    .dpl = envDPL,
  };
}

void cleanupModel(T3DModel *model) {
  t3d_model_free(model);
};

// create an Actor struct, applying base pos/rot/scale + draw block and model material
Actor setupActor(uint32_t id, ModelData *modelData, const float pos[3], const float rot[4], const float scale[3], uint32_t fbCount) {
  Actor actor = (Actor) {
    .id = id,
    .pos = {pos[0], pos[1], pos[2]},
    .staticPos = {pos[0], pos[1], pos[2]},
    .rot = {rot[1], rot[3], -rot[2], rot[0]},
    .scale = {scale[0], scale[1], scale[2]},
    .dpl = modelData->dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * fbCount),
    .model = modelData->model,
    .skip = false,
  };
  return actor;
}

void deleteActor(Actor *actor) {
  free_uncached(actor->modelMat);
  actor->skip = true;
}

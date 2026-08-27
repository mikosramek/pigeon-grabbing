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
Actor setupActor(
  uint32_t id,
  ModelData *modelData,
  const float pos[3],
  const float rot[4],
  const float scale[3],
  bool skip,
  bool skipCulling,
  uint32_t fbCount
) {
  T3DModel *model = modelData->model;
  Actor actor = (Actor) {
    .id = id,
    .pos = {pos[0], pos[1], pos[2]},
    .staticPos = {pos[0], pos[1], pos[2]},
    .rot = {rot[1], rot[3], -rot[2], rot[0]},
    .scale = {scale[0], scale[2], scale[1]},
    .dpl = modelData->dpl,
    .modelMat = malloc_uncached(sizeof(T3DMat4FP) * fbCount),
    .model = model,
    .skip = skip,
    .skipCulling = skipCulling,
    .worldMin = {
      (int16_t)(pos[0] + model->aabbMin[0]),
      (int16_t)(pos[1] + model->aabbMin[1]),
      (int16_t)(pos[2] + model->aabbMin[2]),
    },
    .worldMax = {
      (int16_t)(pos[0] + model->aabbMax[0]),
      (int16_t)(pos[1] + model->aabbMax[1]),
      (int16_t)(pos[2] + model->aabbMax[2]),
    }
  };
  return actor;
}

void deleteActor(Actor *actor) {
  free_uncached(actor->modelMat);
  // actor->skip = true;
}

bool shouldCull(Actor *actor, fm_vec3_t playerPosition, float cameraAngle) {
  if (actor->skipCulling) {
    return false;
  }
  
  fm_vec3_t actorPosition = {{ actor->pos[0], actor->pos[1], actor->pos[2] }};
  if (fabsf(fm_vec3_distance(&actorPosition, &playerPosition)) < 50.0f) {
    return false;
  }
  fm_vec3_sub(&actorPosition, &actorPosition, &playerPosition);
  fm_vec3_norm(&actorPosition, &actorPosition);

  float angleDiff = atan2(actorPosition.z, actorPosition.x) - cameraAngle;

  if (angleDiff > T3D_DEG_TO_RAD(180)) {
    angleDiff -= T3D_DEG_TO_RAD(360);
  }

  if (angleDiff < T3D_DEG_TO_RAD(-180)) {
    angleDiff += T3D_DEG_TO_RAD(360); 
  }

  // bool isVisible = angle > leftThreshold && angle < rightThreshold;
  return fabsf(angleDiff) > T3D_DEG_TO_RAD(90);
}
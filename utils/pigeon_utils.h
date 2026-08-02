#ifndef PIGEON_UTILS_H
#define PIGEON_UTILS_H

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

typedef struct {
  uint32_t id;
  float pos[3];
  float rot[3];
  float scale[3];

  rspq_block_t *dpl;
  T3DMat4FP *modelMat;
} Actor;

rspq_block_t* setupModel (const char *modelPath);

Actor setupActor(uint32_t id, rspq_block_t *dpl, const float pos[3], const float rot[3], const float scale[3], uint32_t fbCount);

#endif
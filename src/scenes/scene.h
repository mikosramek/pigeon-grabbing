#ifndef SCENE_H
#define SCENE_H

#include "../utils/pigeon_utils.h"

typedef struct {
  uint32_t id;
  Actor *actors;
  uint32_t actorCount;

  T3DModel **models;
  uint32_t modelCount;
} Scene;

#endif

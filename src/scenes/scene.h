#ifndef SCENE_H
#define SCENE_H

#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

typedef struct {
  char *name;
  uint32_t id;
  Actor *actors;
  uint32_t actorCount;

  struct Entity *entities;
  uint32_t entityCount;

  T3DModel **models;
  uint32_t modelCount;
} Scene;

#endif

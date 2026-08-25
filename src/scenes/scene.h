#ifndef SCENE_H
#define SCENE_H

#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

typedef struct {
  uint32_t id;
  fm_vec3_t spawn; // Player position (y is ignored)
  float rotationAngle; // Player rotation in radians
} SpawnPoint;

typedef struct {
  fm_vec3_t aabbMin;
  fm_vec3_t aabbMax;
  uint32_t targetSceneID;
  uint32_t targetSpawnPointID;
} Door;

typedef struct {
  char *name;
  uint32_t id;
  Actor *actors;
  uint32_t actorCount;

  struct Entity *entities;
  uint32_t entityCount;

  T3DModel **models;
  uint32_t modelCount;

  SpawnPoint *spawns;
  uint32_t spawnCount;
  
  Door *doors;
  uint32_t doorCount;
} Scene;

#endif

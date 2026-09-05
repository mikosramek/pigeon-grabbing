#ifndef SCENE_H
#define SCENE_H

#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

typedef struct {
  uint32_t id;
  fm_vec3_t spawn; // Player position (y is ignored)
  float angle; // Player z rotation in radians
} SpawnPoint;

typedef struct {
  fm_vec3_t aabbMin;
  fm_vec3_t aabbMax;
  uint32_t targetSceneID;
  uint32_t targetSpawnPointID;
} Door;

enum ColliderType {
  COLLIDER_AABB,
  COLLIDER_OBB
};
typedef struct {
  fm_vec3_t aabbMin;
  fm_vec3_t aabbMax;
  float pos[3];
  float rot[4];
  float scale[3];
  enum ColliderType type;
} Collider;

typedef struct {
  fm_vec3_t aabbMin;
  fm_vec3_t aabbMax;
  float y;
} Floor;

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

  Collider *colliders;
  uint32_t colliderCount;

  Floor *floors;
  uint32_t floorCount;
} Scene;

#endif

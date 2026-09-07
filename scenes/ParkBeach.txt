/*
* PARKBEACH SCENE
* GENERATED ON 2026-09-06
*/
// INCLUDES
#include "parkBeach.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

// ENTITIES


#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene ParkBeach = (Scene) {
  .id = 2,
  .name = "ParkBeach",
  .actorCount = 1,
  .modelCount = 1,
  .entityCount = 0,
  .doorCount = 2,
  .spawnCount = 2,
  .colliderCount = 10,
  .floorCount = 0,
};

Scene *getBaseParkBeach() {
  return &ParkBeach;
}

// Load all the pieces for the ParkBeach scene
Scene *createParkBeach(void) {
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  SpawnPoint *spawns = malloc_uncached(sizeof(SpawnPoint) * ParkBeach.spawnCount);
  Door *doors = malloc_uncached(sizeof(Door) * ParkBeach.doorCount);
  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * ParkBeach.modelCount);
  Actor *actors = malloc_uncached(sizeof(Actor) * ParkBeach.actorCount);
  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * ParkBeach.entityCount);
  Collider *colliders = malloc_uncached(sizeof(Collider) * ParkBeach.colliderCount);
  Floor *floors = malloc_uncached(sizeof(Floor) * ParkBeach.floorCount);

  // SPAWN POINT SETUP
  spawns[0] = (SpawnPoint){
    .id = 5,
    .angle = -0.7071,
    .spawn = (fm_vec3_t){{ -6.6824f * xPositionMultiplier, -0, 0.2156f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 6,
    .angle = -1.0,
    .spawn = (fm_vec3_t){{ 9.9456f * xPositionMultiplier, -0, -36.2588f * zPositionMultiplier }},
  };

  ParkBeach.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 3,
    .targetSceneID = 1,
    .aabbMin = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) - (1.0f * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) + (1.0f * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
  };
  doors[1] = (Door){
    .targetSpawnPointID = 0,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (10.0f * xPositionMultiplier) - (5.0f * xPositionMultiplier), 0, (-39.0f * zPositionMultiplier) - (1.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (10.0f * xPositionMultiplier) + (5.0f * xPositionMultiplier), 0, (-39.0f * zPositionMultiplier) + (1.0f * zPositionMultiplier) }},
  };

  ParkBeach.doors = doors;

  // MODEL IMPORT
	ModelData park_beach = setupModel("rom:/park_beach.t3dm");


	models[0] = park_beach.model;

  ParkBeach.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &park_beach,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors

  ParkBeach.actors = actors;

  // Entities

  ParkBeach.entities = entities;

  // Colliders
  colliders[0] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (11.364f * xPositionMultiplier) - (1.0f * xPositionMultiplier), 0, (-0.0502f * zPositionMultiplier) - (8.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (11.364f * xPositionMultiplier) + (1.0f * xPositionMultiplier), 0, (-0.0502f * zPositionMultiplier) + (8.0f * zPositionMultiplier) }},
    .pos = { 11.364f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0502f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 1.0f * xPositionMultiplier, 1.0f * yPositionMultiplier, 8.0f * zPositionMultiplier },
  };
  colliders[1] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (9.2426f * xPositionMultiplier) - (2.0f * xPositionMultiplier), 0, (-13.5858f * zPositionMultiplier) - (4.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (9.2426f * xPositionMultiplier) + (2.0f * xPositionMultiplier), 0, (-13.5858f * zPositionMultiplier) + (4.0f * zPositionMultiplier) }},
    .pos = { 9.2426f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.5858f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 2.0f * xPositionMultiplier, 1.0f * yPositionMultiplier, 4.0f * zPositionMultiplier },
  };
  colliders[2] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (15.0208f * xPositionMultiplier) - (2.0f * xPositionMultiplier), 0, (-19.364f * zPositionMultiplier) - (4.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (15.0208f * xPositionMultiplier) + (2.0f * xPositionMultiplier), 0, (-19.364f * zPositionMultiplier) + (4.0f * zPositionMultiplier) }},
    .pos = { 15.0208f * xPositionMultiplier, 0.0f * yPositionMultiplier, -19.364f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 2.0f * xPositionMultiplier, 1.0f * yPositionMultiplier, 4.0f * zPositionMultiplier },
  };
  colliders[3] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (16.4649f * xPositionMultiplier) - (3.0f * xPositionMultiplier), 0, (-12.3228f * zPositionMultiplier) - (2.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (16.4649f * xPositionMultiplier) + (3.0f * xPositionMultiplier), 0, (-12.3228f * zPositionMultiplier) + (2.0f * zPositionMultiplier) }},
    .pos = { 16.4649f * xPositionMultiplier, 0.0f * yPositionMultiplier, -12.3228f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 3.0f * xPositionMultiplier, 1.0f * yPositionMultiplier, 2.0f * zPositionMultiplier },
  };
  colliders[4] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (6.0f * xPositionMultiplier) - (1.0f * xPositionMultiplier), 0, (-10.0f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (6.0f * xPositionMultiplier) + (1.0f * xPositionMultiplier), 0, (-10.0f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
    .pos = { 6.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -10.0f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, -0.3266f },
    .scale = { 1.0f * scaleMultiplier, 5.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[5] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (21.3848f * xPositionMultiplier) - (10.0f * xPositionMultiplier), 0, (-29.9706f * zPositionMultiplier) - (1.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (21.3848f * xPositionMultiplier) + (10.0f * xPositionMultiplier), 0, (-29.9706f * zPositionMultiplier) + (1.0f * zPositionMultiplier) }},
    .pos = { 21.3848f * xPositionMultiplier, 0.0f * yPositionMultiplier, -29.9706f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 10.0f * xPositionMultiplier, 1.0f * yPositionMultiplier, 1.0f * zPositionMultiplier },
  };
  colliders[6] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) - (4.0f * xPositionMultiplier), 0, (-20.0f * zPositionMultiplier) - (15.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) + (4.0f * xPositionMultiplier), 0, (-20.0f * zPositionMultiplier) + (15.0f * zPositionMultiplier) }},
    .pos = { -9.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -20.0f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, -0.3266f },
    .scale = { 4.0f * scaleMultiplier, 15.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[7] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (-3.0f * xPositionMultiplier) - (8.0f * xPositionMultiplier), 0, (-40.0f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-3.0f * xPositionMultiplier) + (8.0f * xPositionMultiplier), 0, (-40.0f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
    .pos = { -3.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -40.0f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, -0.3266f },
    .scale = { 8.0f * scaleMultiplier, 5.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[8] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (23.0f * xPositionMultiplier) - (8.0f * xPositionMultiplier), 0, (-40.0f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (23.0f * xPositionMultiplier) + (8.0f * xPositionMultiplier), 0, (-40.0f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
    .pos = { 23.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -40.0f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, -0.3266f },
    .scale = { 8.0f * scaleMultiplier, 5.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[9] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (5.0f * xPositionMultiplier) - (15.0f * xPositionMultiplier), 0, (10.0f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (5.0f * xPositionMultiplier) + (15.0f * xPositionMultiplier), 0, (10.0f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
    .pos = { 5.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.0f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, -0.3266f },
    .scale = { 15.0f * scaleMultiplier, 5.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };

  ParkBeach.colliders = colliders;

  // Floors

  ParkBeach.floors = floors;
  
  return &ParkBeach;  
}

// Unload the ParkBeach scene
// Call via `rdpq_call_deferred(unloadParkBeach, NULL);` for safety
void unloadParkBeach(void *arg) {
  for (int i = 0; i < ParkBeach.modelCount; i++) {
    cleanupModel(ParkBeach.models[i]);
  }

  free_uncached(ParkBeach.models);

  for (int i = 0; i < ParkBeach.actorCount; i++) {
    deleteActor(&ParkBeach.actors[i]);
  }

  free_uncached(ParkBeach.actors);
  free_uncached(ParkBeach.entities);
  free_uncached(ParkBeach.spawns);
  free_uncached(ParkBeach.doors);
  free_uncached(ParkBeach.colliders);
  free_uncached(ParkBeach.floors);
}

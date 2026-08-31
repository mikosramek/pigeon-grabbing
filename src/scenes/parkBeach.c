/*
* PARKBEACH SCENE
* GENERATED ON 2026-08-28
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
};

Scene *getBaseParkBeach() {
  return &ParkBeach;
}

// LOAD FUNCTION
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
    .aabbMin = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) - (1.0 * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) - (5.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-9.0f * xPositionMultiplier) + (1.0 * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) + (5.0 * zPositionMultiplier) }},
  };
  doors[1] = (Door){
    .targetSpawnPointID = 0,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (10.0f * xPositionMultiplier) - (5.0 * xPositionMultiplier), 0, (-39.0f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (10.0f * xPositionMultiplier) + (5.0 * xPositionMultiplier), 0, (-39.0f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
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
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors

  ParkBeach.actors = actors;

  // Entities

  ParkBeach.entities = entities;
  
  return &ParkBeach;  
}

// UNLOAD FUNCTION
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
}

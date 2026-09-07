/*
* PARKNORTH SCENE
* GENERATED ON 2026-09-06
*/
// INCLUDES
#include "parkNorth.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

// ENTITIES
#include "../entities/feather.h"


#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene ParkNorth = (Scene) {
  .id = 1,
  .name = "ParkNorth",
  .actorCount = 23,
  .modelCount = 7,
  .entityCount = 1,
  .doorCount = 3,
  .spawnCount = 3,
  .colliderCount = 0,
  .floorCount = 0,
};

Scene *getBaseParkNorth() {
  return &ParkNorth;
}

// Load all the pieces for the ParkNorth scene
Scene *createParkNorth(void) {
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  SpawnPoint *spawns = malloc_uncached(sizeof(SpawnPoint) * ParkNorth.spawnCount);
  Door *doors = malloc_uncached(sizeof(Door) * ParkNorth.doorCount);
  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * ParkNorth.modelCount);
  Actor *actors = malloc_uncached(sizeof(Actor) * ParkNorth.actorCount);
  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * ParkNorth.entityCount);
  Collider *colliders = malloc_uncached(sizeof(Collider) * ParkNorth.colliderCount);
  Floor *floors = malloc_uncached(sizeof(Floor) * ParkNorth.floorCount);

  // SPAWN POINT SETUP
  spawns[0] = (SpawnPoint){
    .id = 2,
    .angle = 1.56,
    .spawn = (fm_vec3_t){{ 0.0f * xPositionMultiplier, -0, -0.0f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 3,
    .angle = 1.1031,
    .spawn = (fm_vec3_t){{ 25.9677f * xPositionMultiplier, -0, 25.0361f * zPositionMultiplier }},
  };
  spawns[2] = (SpawnPoint){
    .id = 4,
    .angle = 1.56,
    .spawn = (fm_vec3_t){{ -29.9851f * xPositionMultiplier, -0, 9.0247f * zPositionMultiplier }},
  };

  ParkNorth.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (0.0f * xPositionMultiplier) - (5.0f * xPositionMultiplier), 0, (-4.0133f * zPositionMultiplier) - (1.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (0.0f * xPositionMultiplier) + (5.0f * xPositionMultiplier), 0, (-4.0133f * zPositionMultiplier) + (1.0f * zPositionMultiplier) }},
  };
  doors[1] = (Door){
    .targetSpawnPointID = -1,
    .targetSceneID = -1,
    .aabbMin = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) - (5.0f * xPositionMultiplier), 0, (5.9867f * zPositionMultiplier) - (1.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) + (5.0f * xPositionMultiplier), 0, (5.9867f * zPositionMultiplier) + (1.0f * zPositionMultiplier) }},
  };
  doors[2] = (Door){
    .targetSpawnPointID = 5,
    .targetSceneID = 2,
    .aabbMin = (fm_vec3_t){{ (29.0f * xPositionMultiplier) - (1.0f * xPositionMultiplier), 0, (24.9867f * zPositionMultiplier) - (5.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (29.0f * xPositionMultiplier) + (1.0f * xPositionMultiplier), 0, (24.9867f * zPositionMultiplier) + (5.0f * zPositionMultiplier) }},
  };

  ParkNorth.doors = doors;

  // MODEL IMPORT
	ModelData fat_pigeon = setupModel("rom:/fat_pigeon.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData park_north_walls = setupModel("rom:/park_north_walls.t3dm");
	ModelData park_north_ground = setupModel("rom:/park_north_ground.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");


	models[0] = fat_pigeon.model;
	models[1] = feather.model;
	models[2] = iron_trim.model;
	models[3] = rock_post.model;
	models[4] = park_north_walls.model;
	models[5] = park_north_ground.model;
	models[6] = rock_wall_long.model;

  ParkNorth.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &park_north_walls,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &park_north_ground,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -9.3386f * xPositionMultiplier, -1.0f * yPositionMultiplier, 22.1094f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0505f, -0.0f, 0.9987f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 7.9321f * xPositionMultiplier, -4.0f * yPositionMultiplier, 28.346f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.4224f, -0.0f, 0.9064f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.7416f * xPositionMultiplier, 0.0f * yPositionMultiplier, 32.1839f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0223f, -0.0f, 0.9998f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 6.3329f * xPositionMultiplier, -3.0f * yPositionMultiplier, 15.9527f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.8822f, -0.0f, 0.4709f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.1819f * xPositionMultiplier, -2.0f * yPositionMultiplier, 14.2736f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.188f, -0.0f, 0.9822f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 0.8006f * xPositionMultiplier, -3.7995f * yPositionMultiplier, 23.4648f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 0.9064f },
    /* SCALE        */ (float[3]){ 3.3501f * scaleMultiplier, 3.3501f * scaleMultiplier, 1.009f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.9295f * xPositionMultiplier, -2.076f * yPositionMultiplier, -7.026f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.7879f * xPositionMultiplier, -2.076f * yPositionMultiplier, -7.111f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, -0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.0824f * xPositionMultiplier, -2.076f * yPositionMultiplier, 9.3107f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.1972f * xPositionMultiplier, -2.076f * yPositionMultiplier, 0.0391f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0123f, -0.0f, 0.9999f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.5337f * xPositionMultiplier, 1.924f * yPositionMultiplier, -7.026f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -4.3921f * xPositionMultiplier, 1.924f * yPositionMultiplier, -7.111f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.1012f * xPositionMultiplier, -2.8624f * yPositionMultiplier, 11.8327f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, -0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.7054f * xPositionMultiplier, 1.1376f * yPositionMultiplier, 11.8327f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.1012f * xPositionMultiplier, -2.8624f * yPositionMultiplier, 25.5677f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, -0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.7054f * xPositionMultiplier, 1.1376f * yPositionMultiplier, 25.5677f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.0824f * xPositionMultiplier, -2.076f * yPositionMultiplier, 30.9063f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &fat_pigeon,
    /* POSITION     */ (float[3]){ -25.6237f * xPositionMultiplier, 2.0333f * yPositionMultiplier, 24.2008f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.978f, -0.0f, 0.2088f },
    /* SCALE        */ (float[3]){ 0.6296f * scaleMultiplier, 0.7065f * scaleMultiplier, 0.5139f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -5.0418f * xPositionMultiplier, -2.076f * yPositionMultiplier, 0.0581f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0123f, -0.0f, 0.9999f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -25.6195f * xPositionMultiplier, -3.7033f * yPositionMultiplier, 24.2365f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier, 1.4612f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ 0.8384f * xPositionMultiplier, 1.1246f * yPositionMultiplier, 23.4715f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.7218f, -0.0f, 0.6921f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  ParkNorth.actors = actors;

  // Entities
	entities[0] = feather_create(1, &actors[22]);

  ParkNorth.entities = entities;

  // Colliders

  ParkNorth.colliders = colliders;

  // Floors

  ParkNorth.floors = floors;
  
  return &ParkNorth;  
}

// Unload the ParkNorth scene
// Call via `rdpq_call_deferred(unloadParkNorth, NULL);` for safety
void unloadParkNorth(void *arg) {
  for (int i = 0; i < ParkNorth.modelCount; i++) {
    cleanupModel(ParkNorth.models[i]);
  }

  free_uncached(ParkNorth.models);

  for (int i = 0; i < ParkNorth.actorCount; i++) {
    deleteActor(&ParkNorth.actors[i]);
  }

  free_uncached(ParkNorth.actors);
  free_uncached(ParkNorth.entities);
  free_uncached(ParkNorth.spawns);
  free_uncached(ParkNorth.doors);
  free_uncached(ParkNorth.colliders);
  free_uncached(ParkNorth.floors);
}

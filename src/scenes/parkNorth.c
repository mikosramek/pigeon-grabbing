/*
* PARKNORTH SCENE
* GENERATED ON 2026-08-26
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
};

Scene *getBaseParkNorth() {
  return &ParkNorth;
}

// LOAD FUNCTION
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

  // SPAWN POINT SETUP
  spawns[0] = (SpawnPoint){
    .id = 3,
    .angle = 1.559999942779541,
    .spawn = (fm_vec3_t){{ 0.0f * xPositionMultiplier, -0, -0.0f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 4,
    .angle = 1.1030865907669067,
    .spawn = (fm_vec3_t){{ 25.97f * xPositionMultiplier, -0, 25.04f * zPositionMultiplier }},
  };
  spawns[2] = (SpawnPoint){
    .id = 5,
    .angle = 1.559999942779541,
    .spawn = (fm_vec3_t){{ -29.99f * xPositionMultiplier, -0, 9.02f * zPositionMultiplier }},
  };

  ParkNorth.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (0.0f * xPositionMultiplier) - (5.0 * xPositionMultiplier), 0, (-4.01f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (0.0f * xPositionMultiplier) + (5.0 * xPositionMultiplier), 0, (-4.01f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
  };
  doors[1] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) - (5.0 * xPositionMultiplier), 0, (5.99f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-30.0f * xPositionMultiplier) + (5.0 * xPositionMultiplier), 0, (5.99f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
  };
  doors[2] = (Door){
    .targetSpawnPointID = -1,
    .targetSceneID = -1,
    .aabbMin = (fm_vec3_t){{ (29.0f * xPositionMultiplier) - (1.0 * xPositionMultiplier), 0, (24.99f * zPositionMultiplier) - (5.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (29.0f * xPositionMultiplier) + (1.0 * xPositionMultiplier), 0, (24.99f * zPositionMultiplier) + (5.0 * zPositionMultiplier) }},
  };

  ParkNorth.doors = doors;

  // MODEL IMPORT
	ModelData fat_pigeon = setupModel("rom:/fat_pigeon.t3dm");
	ModelData park_north_ground = setupModel("rom:/park_north_ground.t3dm");
	ModelData park_north_walls = setupModel("rom:/park_north_walls.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");


	models[0] = fat_pigeon.model;
	models[1] = park_north_ground.model;
	models[2] = park_north_walls.model;
	models[3] = iron_trim.model;
	models[4] = rock_wall_long.model;
	models[5] = feather.model;
	models[6] = rock_post.model;

  ParkNorth.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &park_north_walls,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &park_north_ground,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -9.34f * xPositionMultiplier, -1.0f * yPositionMultiplier, 22.11f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.05f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 7.93f * xPositionMultiplier, -4.0f * yPositionMultiplier, 28.35f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.91f, 0.0f, 0.0f, 0.42f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.74f * xPositionMultiplier, 0.0f * yPositionMultiplier, 32.18f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.02f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 6.33f * xPositionMultiplier, -3.0f * yPositionMultiplier, 15.95f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.47f, 0.0f, 0.0f, 0.88f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -3.18f * xPositionMultiplier, -2.0f * yPositionMultiplier, 14.27f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.98f, 0.0f, 0.0f, 0.19f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 0.8f * xPositionMultiplier, -3.8f * yPositionMultiplier, 23.46f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.91f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 3.35f * scaleMultiplier, 3.35f * scaleMultiplier, 1.01f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.93f * xPositionMultiplier, -2.08f * yPositionMultiplier, -7.03f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.79f * xPositionMultiplier, -2.08f * yPositionMultiplier, -7.11f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.08f * xPositionMultiplier, -2.08f * yPositionMultiplier, 9.31f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.2f * xPositionMultiplier, -2.08f * yPositionMultiplier, 0.04f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.01f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.53f * xPositionMultiplier, 1.92f * yPositionMultiplier, -7.03f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -4.39f * xPositionMultiplier, 1.92f * yPositionMultiplier, -7.11f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.1f * xPositionMultiplier, -2.86f * yPositionMultiplier, 11.83f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.71f * xPositionMultiplier, 1.14f * yPositionMultiplier, 11.83f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -24.1f * xPositionMultiplier, -2.86f * yPositionMultiplier, 25.57f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -23.71f * xPositionMultiplier, 1.14f * yPositionMultiplier, 25.57f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -24.08f * xPositionMultiplier, -2.08f * yPositionMultiplier, 30.91f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &fat_pigeon,
    /* POSITION     */ (float[3]){ -25.62f * xPositionMultiplier, 2.03f * yPositionMultiplier, 24.2f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.21f, 0.0f, 0.0f, -0.98f },
    /* SCALE        */ (float[3]){ 0.63f * scaleMultiplier, 0.71f * scaleMultiplier, 0.51f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -5.04f * xPositionMultiplier, -2.08f * yPositionMultiplier, 0.06f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.01f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -25.62f * xPositionMultiplier, -3.7f * yPositionMultiplier, 24.24f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.46f * scaleMultiplier, 1.46f * scaleMultiplier, 1.46f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ 0.84f * xPositionMultiplier, 1.12f * yPositionMultiplier, 23.47f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.69f, 0.0f, 0.0f, 0.72f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  ParkNorth.actors = actors;

  // Entities
	entities[0] = createFeather(1, &actors[22]);

  ParkNorth.entities = entities;
  
  return &ParkNorth;  
}

// UNLOAD FUNCTION
void unloadParkNorth(void) {
  for (int i = 0; i < ParkNorth.modelCount; i++) {
    // cleanupModel(ParkNorth.models[i]);
  }

  // free_uncached(ParkNorth.models);

  for (int i = 0; i < ParkNorth.actorCount; i++) {
    deleteActor(&ParkNorth.actors[i]);
  }

  // free_uncached(ParkNorth.actors);
  // free_uncached(ParkNorth.entities);
  // free_uncached(ParkNorth.spawns);
  // free_uncached(ParkNorth.doors);
}

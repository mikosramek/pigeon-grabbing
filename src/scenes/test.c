/*
* TEST SCENE
* GENERATED ON 2026-08-26
*/
// INCLUDES
#include "test.h"

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

static Scene Test = (Scene) {
  .id = -1,
  .name = "Test",
  .actorCount = 14,
  .modelCount = 3,
  .entityCount = 1,
  .doorCount = 1,
  .spawnCount = 1,
};

Scene *getBaseTest() {
  return &Test;
}

// LOAD FUNCTION
Scene *createTest(void) {
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  SpawnPoint *spawns = malloc_uncached(sizeof(SpawnPoint) * Test.spawnCount);
  Door *doors = malloc_uncached(sizeof(Door) * Test.doorCount);
  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Test.modelCount);
  Actor *actors = malloc_uncached(sizeof(Actor) * Test.actorCount);
  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Test.entityCount);

  // SPAWN POINT SETUP
  spawns[0] = (SpawnPoint){
    .id = -1,
    .angle = 0.0,
    .spawn = (fm_vec3_t){{ 0.0f * xPositionMultiplier, -0, -0.0f * zPositionMultiplier }},
  };

  Test.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 1,
    .targetSceneID = 0,
    .aabbMin = (fm_vec3_t){{ (-6.32f * xPositionMultiplier) - (1.0 * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) - (2.79 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-6.32f * xPositionMultiplier) + (1.0 * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) + (2.79 * zPositionMultiplier) }},
  };

  Test.doors = doors;

  // MODEL IMPORT
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData test_plane = setupModel("rom:/test_plane.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");


	models[0] = two_cube.model;
	models[1] = test_plane.model;
	models[2] = feather.model;

  Test.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &test_plane,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.41f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.25f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.41f * xPositionMultiplier, 2.0f * yPositionMultiplier, -0.25f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.41f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.25f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.41f * xPositionMultiplier, 4.0f * yPositionMultiplier, 1.75f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 8.41f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.25f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -3.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -7.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 3.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -7.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 0.48f * xPositionMultiplier, 1.02f * yPositionMultiplier, -7.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.85f, 0.15f, -0.3535533845424652f, 0.35f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.33f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.83f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 3.1f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.33f * xPositionMultiplier, 0.0f * yPositionMultiplier, 3.76f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 3.1f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.33f * xPositionMultiplier, 6.2f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 4.75f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -1.31f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.23f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 3.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -3.76f * xPositionMultiplier, 0.8f * yPositionMultiplier, -3.89f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.94f, 0.0f, 0.0f, -0.34f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  Test.actors = actors;

  // Entities
	entities[0] = createFeather(-1, &actors[13]);

  Test.entities = entities;
  
  return &Test;  
}

// UNLOAD FUNCTION
void unloadTest(void) {
  // for (int i = 0; i < Test.modelCount; i++) {
    // cleanupModel(Test.models[i]);
  // }

  // free_uncached(Test.models);

  for (int i = 0; i < Test.actorCount; i++) {
    deleteActor(&Test.actors[i]);
  }

  // free_uncached(Test.actors);
  // free_uncached(Test.entities);
  // free_uncached(Test.spawns);
  // free_uncached(Test.doors);
}

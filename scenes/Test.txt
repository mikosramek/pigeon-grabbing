/*
* TEST SCENE
* GENERATED ON 2026-09-13
*/
// INCLUDES
#include "test.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

// ENTITIES
#include "../entities/pigeon_guide.h"
#include "../entities/feather.h"


#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene Test = (Scene) {
  .id = -1,
  .name = "Test",
  .actorCount = 27,
  .modelCount = 4,
  .entityCount = 4,
  .doorCount = 1,
  .spawnCount = 1,
  .colliderCount = 5,
  .floorCount = 0,
};

Scene *getBaseTest() {
  return &Test;
}

// Load all the pieces for the Test scene
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
  Collider *colliders = malloc_uncached(sizeof(Collider) * Test.colliderCount);
  Floor *floors = malloc_uncached(sizeof(Floor) * Test.floorCount);

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
    .aabbMin = (fm_vec3_t){{ (-6.316f * xPositionMultiplier) - (1.0f * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) - (2.7919f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-6.316f * xPositionMultiplier) + (1.0f * xPositionMultiplier), 0, (-0.0f * zPositionMultiplier) + (2.7919f * zPositionMultiplier) }},
  };

  Test.doors = doors;

  // MODEL IMPORT
	ModelData pigeon_guide = setupModel("rom:/pigeon_guide.t3dm");
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData test_plane = setupModel("rom:/test_plane.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");


	models[0] = pigeon_guide.model;
	models[1] = two_cube.model;
	models[2] = test_plane.model;
	models[3] = feather.model;

  Test.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &test_plane,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.4099f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.2506f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.4099f * xPositionMultiplier, 2.0f * yPositionMultiplier, -0.2506f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.4099f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.2506f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 10.4099f * xPositionMultiplier, 4.0f * yPositionMultiplier, 1.7494f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 8.4099f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.2506f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 21.3786f * xPositionMultiplier, -1.7057f * yPositionMultiplier, -11.2738f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -1.2643f * xPositionMultiplier, -1.7057f * yPositionMultiplier, -8.8541f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -5.1529f * xPositionMultiplier, 1.0249f * yPositionMultiplier, -17.7535f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.1464f, 0.3536f, 0.3535533845424652f, 0.8536f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.3339f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.8254f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 3.098f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.3339f * xPositionMultiplier, 0.0f * yPositionMultiplier, 3.7602f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 3.098f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -6.3339f * xPositionMultiplier, 6.196f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 4.7493f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -20.3216f * xPositionMultiplier, 0.0f * yPositionMultiplier, 21.5098f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 3.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 17.7248f * xPositionMultiplier, 0.0f * yPositionMultiplier, 7.2679f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.3536f, -0.0f, 0.8536f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 12.6035f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.1376f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.3266f, -0.0f, 0.7886f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 3.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -32.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, 32.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 21.3312f * xPositionMultiplier, -1.7057f * yPositionMultiplier, -6.292f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 21.4261f * xPositionMultiplier, -1.7057f * yPositionMultiplier, -1.2626f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.7071f, -0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -15.0902f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.3292f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 3.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -25.0314f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.2627f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 3.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -32.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ 32.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, 0.0f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -1.2643f * xPositionMultiplier, 0.571f * yPositionMultiplier, -8.8541f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.3363f, -0.0f, 0.9418f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &pigeon_guide,
    /* POSITION     */ (float[3]){ 21.3786f * xPositionMultiplier, 0.2066f * yPositionMultiplier, -11.2738f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0065f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 0.732f * scaleMultiplier, 1.6244f * scaleMultiplier, 0.8004f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[25] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 25,
    /* MODEL DATA   */ &pigeon_guide,
    /* POSITION     */ (float[3]){ 21.3312f * xPositionMultiplier, 0.2066f * yPositionMultiplier, -6.292f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0065f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 0.732f * scaleMultiplier, 1.6244f * scaleMultiplier, 0.8004f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[26] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 26,
    /* MODEL DATA   */ &pigeon_guide,
    /* POSITION     */ (float[3]){ 21.4261f * xPositionMultiplier, 0.2066f * yPositionMultiplier, -1.2626f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0f, -0.0065f, -0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 0.732f * scaleMultiplier, 1.6244f * scaleMultiplier, 0.8004f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  Test.actors = actors;

  // Entities
	entities[0] = feather_create(-1, &actors[23]);
	entities[1] = pigeon_guide_create(0, &actors[24]);
	entities[2] = pigeon_guide_create(1, &actors[25]);
	entities[3] = pigeon_guide_create(2, &actors[26]);

  Test.entities = entities;

  // Colliders
  colliders[0] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (-20.3216f * xPositionMultiplier) - (3.3f * xPositionMultiplier), 0, (21.5098f * zPositionMultiplier) - (1.3f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-20.3216f * xPositionMultiplier) + (3.3f * xPositionMultiplier), 0, (21.5098f * zPositionMultiplier) + (1.3f * zPositionMultiplier) }},
    .pos = { -20.3216f * xPositionMultiplier, 0.0f * yPositionMultiplier, 21.5098f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, 1.0f },
    .scale = { 3.3f * scaleMultiplier, 1.3f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[1] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (17.7248f * xPositionMultiplier) - (1.3f * xPositionMultiplier), 0, (7.2679f * zPositionMultiplier) - (1.3f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (17.7248f * xPositionMultiplier) + (1.3f * xPositionMultiplier), 0, (7.2679f * zPositionMultiplier) + (1.3f * zPositionMultiplier) }},
    .pos = { 17.7248f * xPositionMultiplier, 0.0f * yPositionMultiplier, 7.2679f * zPositionMultiplier },
    .rot = { 0.0f, -0.3536f, -0.0f, 0.8536f },
    .scale = { 1.3f * xPositionMultiplier, 1.0f * yPositionMultiplier, 1.3f * zPositionMultiplier },
  };
  colliders[2] = (Collider) {
    .type = COLLIDER_OBB,
    .aabbMin = (fm_vec3_t){{ (12.6035f * xPositionMultiplier) - (1.3f * xPositionMultiplier), 0, (10.1376f * zPositionMultiplier) - (3.3f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (12.6035f * xPositionMultiplier) + (1.3f * xPositionMultiplier), 0, (10.1376f * zPositionMultiplier) + (3.3f * zPositionMultiplier) }},
    .pos = { 12.6035f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.1376f * zPositionMultiplier },
    .rot = { 0.0f, 0.7886f, -0.0f, -0.3266f },
    .scale = { 1.3f * xPositionMultiplier, 1.0f * yPositionMultiplier, 3.3f * zPositionMultiplier },
  };
  colliders[3] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (-15.0902f * xPositionMultiplier) - (3.5f * xPositionMultiplier), 0, (10.3292f * zPositionMultiplier) - (1.5f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-15.0902f * xPositionMultiplier) + (3.5f * xPositionMultiplier), 0, (10.3292f * zPositionMultiplier) + (1.5f * zPositionMultiplier) }},
    .pos = { -15.0902f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.3292f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, 1.0f },
    .scale = { 3.5f * scaleMultiplier, 1.5f * scaleMultiplier, 1.0f * scaleMultiplier },
  };
  colliders[4] = (Collider) {
    .type = COLLIDER_AABB,
    .aabbMin = (fm_vec3_t){{ (-25.0314f * xPositionMultiplier) - (4.0f * xPositionMultiplier), 0, (10.2627f * zPositionMultiplier) - (2.0f * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (-25.0314f * xPositionMultiplier) + (4.0f * xPositionMultiplier), 0, (10.2627f * zPositionMultiplier) + (2.0f * zPositionMultiplier) }},
    .pos = { -25.0314f * xPositionMultiplier, 0.0f * yPositionMultiplier, 10.2627f * zPositionMultiplier },
    .rot = { 0.0f, 0.0f, -0.0f, 1.0f },
    .scale = { 4.0f * scaleMultiplier, 2.0f * scaleMultiplier, 1.0f * scaleMultiplier },
  };

  Test.colliders = colliders;

  // Floors

  Test.floors = floors;
  
  return &Test;  
}

// Unload the Test scene
// Call via `rdpq_call_deferred(unloadTest, NULL);` for safety
void unloadTest(void *arg) {
  for (int i = 0; i < Test.modelCount; i++) {
    cleanupModel(Test.models[i]);
  }

  free_uncached(Test.models);

  for (int i = 0; i < Test.actorCount; i++) {
    deleteActor(&Test.actors[i]);
  }

  free_uncached(Test.actors);
  free_uncached(Test.entities);
  free_uncached(Test.spawns);
  free_uncached(Test.doors);
  free_uncached(Test.colliders);
  free_uncached(Test.floors);
}

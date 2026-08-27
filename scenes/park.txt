/*
* PARK SCENE
* GENERATED ON 2026-08-26
*/
// INCLUDES
#include "park.h"

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

static Scene Park = (Scene) {
  .id = 0,
  .name = "Park",
  .actorCount = 59,
  .modelCount = 11,
  .entityCount = 1,
  .doorCount = 1,
  .spawnCount = 2,
};

Scene *getBasePark() {
  return &Park;
}

// LOAD FUNCTION
Scene *createPark(void) {
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  SpawnPoint *spawns = malloc_uncached(sizeof(SpawnPoint) * Park.spawnCount);
  Door *doors = malloc_uncached(sizeof(Door) * Park.doorCount);
  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
  Actor *actors = malloc_uncached(sizeof(Actor) * Park.actorCount);
  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);

  // SPAWN POINT SETUP
  spawns[0] = (SpawnPoint){
    .id = 0,
    .angle = -1.5,
    .spawn = (fm_vec3_t){{ 0.28f * xPositionMultiplier, -0, 21.65f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 1,
    .angle = -4.599999904632568,
    .spawn = (fm_vec3_t){{ 0.46f * xPositionMultiplier, -0, -39.49f * zPositionMultiplier }},
  };

  Park.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 3,
    .targetSceneID = 1,
    .aabbMin = (fm_vec3_t){{ (0.53f * xPositionMultiplier) - (4.95 * xPositionMultiplier), 0, (-44.87f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (0.53f * xPositionMultiplier) + (4.95 * xPositionMultiplier), 0, (-44.87f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
  };

  Park.doors = doors;

  // MODEL IMPORT
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData park = setupModel("rom:/park.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData tree_line = setupModel("rom:/tree_line.t3dm");
	ModelData tree_tops = setupModel("rom:/tree_tops.t3dm");
	ModelData path = setupModel("rom:/path.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData simple_tree = setupModel("rom:/simple_tree.t3dm");


	models[0] = stump.model;
	models[1] = park.model;
	models[2] = iron_trim.model;
	models[3] = rock_wall_long.model;
	models[4] = plant.model;
	models[5] = feather.model;
	models[6] = tree_line.model;
	models[7] = tree_tops.model;
	models[8] = path.model;
	models[9] = rock_post.model;
	models[10] = simple_tree.model;

  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -4.27f * xPositionMultiplier, -1.83f * yPositionMultiplier, 14.86f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.02f },
    /* SCALE        */ (float[3]){ 1.97f * scaleMultiplier, 1.97f * scaleMultiplier, 1.3f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -4.21f * xPositionMultiplier, -1.83f * yPositionMultiplier, -34.34f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.01f },
    /* SCALE        */ (float[3]){ 1.97f * scaleMultiplier, 1.97f * scaleMultiplier, 1.3f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 4.82f * xPositionMultiplier, -1.83f * yPositionMultiplier, -34.39f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.69f, 0.0f, 0.0f, -0.72f },
    /* SCALE        */ (float[3]){ 1.97f * scaleMultiplier, 1.97f * scaleMultiplier, 1.3f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.53f * xPositionMultiplier, -1.83f * yPositionMultiplier, 14.71f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.01f },
    /* SCALE        */ (float[3]){ 1.97f * scaleMultiplier, 1.97f * scaleMultiplier, 1.3f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 5.06f * xPositionMultiplier, -2.53f * yPositionMultiplier, 21.59f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.84f * xPositionMultiplier, -2.53f * yPositionMultiplier, -41.07f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -3.73f * xPositionMultiplier, -2.53f * yPositionMultiplier, -41.01f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.7f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.09f * xPositionMultiplier, -2.53f * yPositionMultiplier, 21.57f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.7f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.7f * xPositionMultiplier, 1.47f * yPositionMultiplier, 21.58f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.7f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.33f * xPositionMultiplier, 1.47f * yPositionMultiplier, -41.01f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.7f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.44f * xPositionMultiplier, 1.47f * yPositionMultiplier, -41.06f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.67f * xPositionMultiplier, 1.47f * yPositionMultiplier, 21.58f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 4.17f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.56f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.11f * xPositionMultiplier, -0.77f * yPositionMultiplier, 9.78f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.86f, 0.0f, 0.0f, -0.51f },
    /* SCALE        */ (float[3]){ 1.97f * scaleMultiplier, 1.97f * scaleMultiplier, 1.97f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.11f * xPositionMultiplier, -0.28f * yPositionMultiplier, 9.78f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.48f, 0.0f, -0.0f, -0.88f },
    /* SCALE        */ (float[3]){ 1.73f * scaleMultiplier, 1.73f * scaleMultiplier, 1.73f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ -7.29f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.15f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.94f, 0.0f, 0.0f, -0.34f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ -6.54f * xPositionMultiplier, -0.22f * yPositionMultiplier, 11.81f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7f, 0.0f, -0.0f, -0.72f },
    /* SCALE        */ (float[3]){ 0.64f * scaleMultiplier, 0.64f * scaleMultiplier, 0.64f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -5.99f * xPositionMultiplier, -0.42f * yPositionMultiplier, -5.28f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -11.5f * xPositionMultiplier, -0.42f * yPositionMultiplier, -30.33f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.98f, 0.0f, 0.0f, -0.2f },
    /* SCALE        */ (float[3]){ 1.26f * scaleMultiplier, 1.26f * scaleMultiplier, 1.26f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 4.12f * xPositionMultiplier, -0.42f * yPositionMultiplier, -17.96f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.97f, 0.0f, 0.0f, 0.23f },
    /* SCALE        */ (float[3]){ 0.96f * scaleMultiplier, 0.96f * scaleMultiplier, 0.96f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.85f * xPositionMultiplier, -0.24f * yPositionMultiplier, 6.69f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.86f * xPositionMultiplier, -0.24f * yPositionMultiplier, 15.53f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -18.26f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.09f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -9.42f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[25] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 25,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -5.0f * xPositionMultiplier, -0.24f * yPositionMultiplier, 24.39f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[26] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 26,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -7.4f * xPositionMultiplier, 5.12f * yPositionMultiplier, 19.04f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.77f * scaleMultiplier, 0.77f * scaleMultiplier, 0.77f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[27] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 27,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -13.35f * xPositionMultiplier, 5.55f * yPositionMultiplier, 19.56f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.77f * scaleMultiplier, 0.77f * scaleMultiplier, 0.77f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[28] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 28,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.31f * xPositionMultiplier, 4.88f * yPositionMultiplier, 19.33f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.77f * scaleMultiplier, 0.77f * scaleMultiplier, 0.77f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[29] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 29,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -26.88f * xPositionMultiplier, 5.37f * yPositionMultiplier, 16.06f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.79f * scaleMultiplier, 0.79f * scaleMultiplier, 0.79f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[30] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 30,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.41f * xPositionMultiplier, 6.03f * yPositionMultiplier, 10.47f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.72f * scaleMultiplier, 0.72f * scaleMultiplier, 0.72f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[31] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 31,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.31f * xPositionMultiplier, 5.32f * yPositionMultiplier, 5.12f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.72f * scaleMultiplier, 0.46f * scaleMultiplier, 0.72f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[32] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 32,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -4.15f * xPositionMultiplier, 5.24f * yPositionMultiplier, 26.09f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.62f * scaleMultiplier, 0.62f * scaleMultiplier, 0.62f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[33] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 33,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -3.98f * xPositionMultiplier, 5.24f * yPositionMultiplier, 22.29f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.62f * scaleMultiplier, 0.62f * scaleMultiplier, 0.62f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[34] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 34,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -22.75f * xPositionMultiplier, 5.75f * yPositionMultiplier, 19.79f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.77f * scaleMultiplier, 0.77f * scaleMultiplier, 0.77f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[35] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 35,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.27f * xPositionMultiplier, 5.52f * yPositionMultiplier, 19.56f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.77f * scaleMultiplier, 0.77f * scaleMultiplier, 0.77f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[36] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 36,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.27f * xPositionMultiplier, 6.1f * yPositionMultiplier, 5.52f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.94f * scaleMultiplier, 0.6f * scaleMultiplier, 0.94f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[37] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 37,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.66f * xPositionMultiplier, 6.85f * yPositionMultiplier, 12.75f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.11f * scaleMultiplier, 0.71f * scaleMultiplier, 1.11f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[38] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 38,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.31f * xPositionMultiplier, 4.6f * yPositionMultiplier, 22.05f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.25f * scaleMultiplier, 1.25f * scaleMultiplier, 1.25f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[39] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 39,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -11.03f * xPositionMultiplier, 3.7f * yPositionMultiplier, 22.69f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.25f * scaleMultiplier, 1.25f * scaleMultiplier, 1.25f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[40] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 40,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -6.0f * xPositionMultiplier, 5.81f * yPositionMultiplier, 27.31f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 0.76f * scaleMultiplier, 0.76f * scaleMultiplier, 0.76f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[41] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 41,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 19.51f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[42] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 42,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 6.25f * xPositionMultiplier, -0.24f * yPositionMultiplier, 24.38f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[43] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 43,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.35f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[44] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 44,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3f * xPositionMultiplier, -0.24f * yPositionMultiplier, 9.16f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[45] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 45,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3f * xPositionMultiplier, -0.24f * yPositionMultiplier, 18.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[46] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 46,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3f * xPositionMultiplier, -0.24f * yPositionMultiplier, 0.32f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[47] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 47,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 19.51f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.65f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[48] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 48,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.35f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.65f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[49] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 49,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 10.67f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.65f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[50] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 50,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -17.96f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.27f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[51] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 51,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -9.12f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.27f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[52] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 52,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -26.8f * xPositionMultiplier, -0.24f * yPositionMultiplier, -38.27f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[53] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 53,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -4.7f * xPositionMultiplier, -0.24f * yPositionMultiplier, -42.69f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, 0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[54] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 54,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 6.25f * xPositionMultiplier, -0.24f * yPositionMultiplier, -43.07f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.71f, 0.0f, 0.0f, -0.71f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[55] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 55,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 10.67f * xPositionMultiplier, -0.24f * yPositionMultiplier, 19.97f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[56] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 56,
    /* MODEL DATA   */ &park,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[57] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 57,
    /* MODEL DATA   */ &path,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.1f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );

	// Entity Actors
	actors[58] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 58,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -6.54f * xPositionMultiplier, 1.03f * yPositionMultiplier, 11.81f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.96f, 0.0f, 0.0f, 0.26f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  Park.actors = actors;

  // Entities
	entities[0] = createFeather(0, &actors[58]);

  Park.entities = entities;
  
  return &Park;  
}

// UNLOAD FUNCTION
void unloadPark(void) {
  for (int i = 0; i < Park.modelCount; i++) {
    cleanupModel(Park.models[i]);
  }

  free_uncached(Park.models);

  for (int i = 0; i < Park.actorCount; i++) {
    deleteActor(&Park.actors[i]);
  }

  free_uncached(Park.actors);
  free_uncached(Park.entities);
  free_uncached(Park.spawns);
  free_uncached(Park.doors);
}

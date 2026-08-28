/*
* PARK SCENE
* GENERATED ON 2026-08-28
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
    .spawn = (fm_vec3_t){{ 0.2795f * xPositionMultiplier, -0, 21.6501f * zPositionMultiplier }},
  };
  spawns[1] = (SpawnPoint){
    .id = 1,
    .angle = -4.6,
    .spawn = (fm_vec3_t){{ 0.457f * xPositionMultiplier, -0, -39.4884f * zPositionMultiplier }},
  };

  Park.spawns = spawns;

  // DOOR SETUP
  doors[0] = (Door){
    .targetSpawnPointID = 2,
    .targetSceneID = 1,
    .aabbMin = (fm_vec3_t){{ (0.5299f * xPositionMultiplier) - (4.9464 * xPositionMultiplier), 0, (-44.8736f * zPositionMultiplier) - (1.0 * zPositionMultiplier) }},
    .aabbMax = (fm_vec3_t){{ (0.5299f * xPositionMultiplier) + (4.9464 * xPositionMultiplier), 0, (-44.8736f * zPositionMultiplier) + (1.0 * zPositionMultiplier) }},
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
    /* POSITION     */ (float[3]){ -4.2702f * xPositionMultiplier, -1.832f * yPositionMultiplier, 14.8644f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9998f, 0.0f, 0.0f, -0.0208f },
    /* SCALE        */ (float[3]){ 1.9656f * scaleMultiplier, 1.9656f * scaleMultiplier, 1.304f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -4.2126f * xPositionMultiplier, -1.832f * yPositionMultiplier, -34.3359f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, -0.0092f },
    /* SCALE        */ (float[3]){ 1.9656f * scaleMultiplier, 1.9656f * scaleMultiplier, 1.304f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 4.8239f * xPositionMultiplier, -1.832f * yPositionMultiplier, -34.3917f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6909f, 0.0f, 0.0f, -0.723f },
    /* SCALE        */ (float[3]){ 1.9656f * scaleMultiplier, 1.9656f * scaleMultiplier, 1.304f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.5283f * xPositionMultiplier, -1.832f * yPositionMultiplier, 14.713f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999f, 0.0f, 0.0f, -0.013f },
    /* SCALE        */ (float[3]){ 1.9656f * scaleMultiplier, 1.9656f * scaleMultiplier, 1.304f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 5.064f * xPositionMultiplier, -2.5307f * yPositionMultiplier, 21.5867f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7004f, 0.0f, 0.0f, -0.7137f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.8357f * xPositionMultiplier, -2.5307f * yPositionMultiplier, -41.0663f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7086f, 0.0f, 0.0f, -0.7056f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -3.7277f * xPositionMultiplier, -2.5307f * yPositionMultiplier, -41.0142f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7094f, 0.0f, 0.0f, 0.7048f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.0919f * xPositionMultiplier, -2.5307f * yPositionMultiplier, 21.5749f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7116f, 0.0f, 0.0f, 0.7026f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.6961f * xPositionMultiplier, 1.4693f * yPositionMultiplier, 21.5799f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7116f, 0.0f, 0.0f, 0.7026f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.3319f * xPositionMultiplier, 1.4693f * yPositionMultiplier, -41.0116f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7094f, 0.0f, 0.0f, 0.7048f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.4399f * xPositionMultiplier, 1.4693f * yPositionMultiplier, -41.0647f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7086f, 0.0f, 0.0f, -0.7056f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.6683f * xPositionMultiplier, 1.4693f * yPositionMultiplier, 21.5793f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7004f, 0.0f, 0.0f, -0.7137f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 4.1659f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.5637f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.1128f * xPositionMultiplier, -0.769f * yPositionMultiplier, 9.7802f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8598f, 0.0f, 0.0f, -0.5106f },
    /* SCALE        */ (float[3]){ 1.9653f * scaleMultiplier, 1.9653f * scaleMultiplier, 1.9653f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.1128f * xPositionMultiplier, -0.2795f * yPositionMultiplier, 9.7802f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.4782f, 0.0f, -0.0f, -0.8783f },
    /* SCALE        */ (float[3]){ 1.7262f * scaleMultiplier, 1.7262f * scaleMultiplier, 1.7262f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ -7.2926f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.1493f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9415f, 0.0f, 0.0f, -0.3369f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ -6.5421f * xPositionMultiplier, -0.2222f * yPositionMultiplier, 11.8135f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6982f, 0.0f, -0.0f, -0.7159f },
    /* SCALE        */ (float[3]){ 0.6361f * scaleMultiplier, 0.6361f * scaleMultiplier, 0.6361f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -5.9931f * xPositionMultiplier, -0.4248f * yPositionMultiplier, -5.2844f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -11.4988f * xPositionMultiplier, -0.4248f * yPositionMultiplier, -30.3283f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9792f, 0.0f, 0.0f, -0.203f },
    /* SCALE        */ (float[3]){ 1.2601f * scaleMultiplier, 1.2601f * scaleMultiplier, 1.2601f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 4.1198f * xPositionMultiplier, -0.4248f * yPositionMultiplier, -17.9622f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9743f, 0.0f, 0.0f, 0.2252f },
    /* SCALE        */ (float[3]){ 0.9598f * scaleMultiplier, 0.9598f * scaleMultiplier, 0.9598f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.853f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 6.6949f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.8585f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 15.5328f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -18.2565f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.0944f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -9.4186f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[25] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 25,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -5.0024f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 24.3872f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[26] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 26,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -7.4014f * xPositionMultiplier, 5.1166f * yPositionMultiplier, 19.0445f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766f * scaleMultiplier, 0.766f * scaleMultiplier, 0.766f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[27] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 27,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -13.3528f * xPositionMultiplier, 5.5505f * yPositionMultiplier, 19.5571f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766f * scaleMultiplier, 0.766f * scaleMultiplier, 0.766f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[28] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 28,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.3113f * xPositionMultiplier, 4.8752f * yPositionMultiplier, 19.3281f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766f * scaleMultiplier, 0.766f * scaleMultiplier, 0.766f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[29] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 29,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -26.8772f * xPositionMultiplier, 5.367f * yPositionMultiplier, 16.0574f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.7905f * scaleMultiplier, 0.7905f * scaleMultiplier, 0.7905f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[30] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 30,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.4121f * xPositionMultiplier, 6.0268f * yPositionMultiplier, 10.4711f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.7241f * scaleMultiplier, 0.7241f * scaleMultiplier, 0.7241f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[31] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 31,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.3053f * xPositionMultiplier, 5.3241f * yPositionMultiplier, 5.121f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.7199f * scaleMultiplier, 0.4604f * scaleMultiplier, 0.7199f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[32] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 32,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -4.1525f * xPositionMultiplier, 5.2352f * yPositionMultiplier, 26.0911f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.6242f * scaleMultiplier, 0.6242f * scaleMultiplier, 0.6242f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[33] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 33,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -3.9792f * xPositionMultiplier, 5.2352f * yPositionMultiplier, 22.2917f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.6242f * scaleMultiplier, 0.6242f * scaleMultiplier, 0.6242f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[34] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 34,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -22.7533f * xPositionMultiplier, 5.7529f * yPositionMultiplier, 19.794f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766f * scaleMultiplier, 0.766f * scaleMultiplier, 0.766f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[35] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 35,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.2656f * xPositionMultiplier, 5.5215f * yPositionMultiplier, 19.5571f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766f * scaleMultiplier, 0.766f * scaleMultiplier, 0.766f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[36] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 36,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.2728f * xPositionMultiplier, 6.1018f * yPositionMultiplier, 5.5239f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.9412f * scaleMultiplier, 0.6019f * scaleMultiplier, 0.9412f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[37] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 37,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.6632f * xPositionMultiplier, 6.8522f * yPositionMultiplier, 12.754f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.1145f * scaleMultiplier, 0.7126f * scaleMultiplier, 1.1145f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[38] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 38,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.3113f * xPositionMultiplier, 4.5959f * yPositionMultiplier, 22.0486f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.2525f * scaleMultiplier, 1.2525f * scaleMultiplier, 1.2525f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[39] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 39,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -11.0271f * xPositionMultiplier, 3.7045f * yPositionMultiplier, 22.6873f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.2525f * scaleMultiplier, 1.2525f * scaleMultiplier, 1.2525f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[40] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 40,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -5.9976f * xPositionMultiplier, 5.8094f * yPositionMultiplier, 27.3104f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 0.7634f * scaleMultiplier, 0.7634f * scaleMultiplier, 0.7634f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[41] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 41,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 19.5113f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[42] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 42,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 6.2545f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 24.3844f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[43] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 43,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3492f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.0f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[44] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 44,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3015f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 9.1596f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[45] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 45,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3015f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 17.9975f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[46] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 46,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3015f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 0.3217f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[47] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 47,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 19.5113f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.6482f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[48] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 48,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 28.3492f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.6482f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[49] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 49,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 10.6734f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.6482f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[50] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 50,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -17.9608f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.2741f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[51] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 51,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -9.1229f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.2741f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[52] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 52,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -26.7987f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -38.2741f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[53] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 53,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -4.704f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -42.693f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, 0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[54] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 54,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 6.2545f * xPositionMultiplier, -0.2366f * yPositionMultiplier, -43.0671f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071f, 0.0f, 0.0f, -0.7071f },
    /* SCALE        */ (float[3]){ 1.0f * scaleMultiplier, 1.0f * scaleMultiplier, 1.0f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[55] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 55,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ 10.6735f * xPositionMultiplier, -0.2366f * yPositionMultiplier, 19.9655f * zPositionMultiplier },
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
    /* POSITION     */ (float[3]){ -6.545f * xPositionMultiplier, 1.027f * yPositionMultiplier, 11.8067f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9644f, 0.0f, 0.0f, 0.2645f },
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
  // for (int i = 0; i < Park.modelCount; i++) {
  //   cleanupModel(Park.models[i]);
  // }

  // free_uncached(Park.models);

  for (int i = 0; i < Park.actorCount; i++) {
    deleteActor(&Park.actors[i]);
  }

  // free_uncached(Park.actors);
  // free_uncached(Park.entities);
  // free_uncached(Park.spawns);
  // free_uncached(Park.doors);
}

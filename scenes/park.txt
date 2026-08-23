/*
* PARK SCENE
* GENERATED ON 2026-08-21
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
  .name = "Park",
  .actorCount = 44,
  .modelCount = 11,
  .entityCount = 1,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData tree_line = setupModel("rom:/tree_line.t3dm");
	ModelData simple_tree = setupModel("rom:/simple_tree.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData tree_tops = setupModel("rom:/tree_tops.t3dm");
	ModelData path = setupModel("rom:/path.t3dm");
	ModelData park = setupModel("rom:/park.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = rock_post.model;
	models[1] = tree_line.model;
	models[2] = simple_tree.model;
	models[3] = stump.model;
	models[4] = iron_trim.model;
	models[5] = feather.model;
	models[6] = rock_wall_long.model;
	models[7] = plant.model;
	models[8] = tree_tops.model;
	models[9] = path.model;
	models[10] = park.model;


  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * Park.actorCount);
	actors[0] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 0,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -4.2702131271362305f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 14.8644380569458f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9997836947441101f, 0.0f, 0.0f, -0.02079819142818451f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -4.212617874145508f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -34.335853576660156f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999579787254333f, 0.0f, 0.0f, -0.00916735827922821f },
    /* SCALE        */ (float[3]){ 1.965580f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 4.8238630294799805f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -34.391693115234375f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6908884644508362f, 0.0f, 0.0f, -0.7229612469673157f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 5.528310775756836f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 14.712958335876465f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999150037765503f, 0.0f, 0.0f, -0.01303967833518982f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 5.063994407653809f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 21.586734771728516f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7004075646400452f, 0.0f, 0.0f, -0.7137432098388672f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 4.835692405700684f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -41.06631851196289f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7085670828819275f, 0.0f, 0.0f, -0.7056434154510498f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -3.7277441024780273f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -41.014198303222656f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7093936800956726f, 0.0f, 0.0f, 0.7048125267028809f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -4.091864585876465f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 21.57490348815918f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7115837931632996f, 0.0f, 0.0f, 0.7026011943817139f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 4.16594123840332f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.563694953918457f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.7689685225486755f * yPositionMultiplier, 9.78023624420166f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8598006367683411f, 0.0f, 0.0f, -0.5106298327445984f },
    /* SCALE        */ (float[3]){ 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.2794775664806366f * yPositionMultiplier, 9.78023624420166f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.4781578779220581f, 0.0f, -0.0f, -0.8782739043235779f },
    /* SCALE        */ (float[3]){ 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ -7.292577743530273f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.149275779724121f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9415283799171448f, 0.0f, 0.0f, -0.3369336724281311f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ -6.542078018188477f * xPositionMultiplier, -0.22218048572540283f * yPositionMultiplier, 11.813546180725098f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6982279419898987f, 0.0f, -0.0f, -0.715875506401062f },
    /* SCALE        */ (float[3]){ 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.6960830688476562f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 21.57993507385254f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7115837931632996f, 0.0f, 0.0f, 0.7026011943817139f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -3.3319411277770996f * xPositionMultiplier, 1.4692573547363281f * yPositionMultiplier, -41.011634826660156f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7093936800956726f, 0.0f, 0.0f, 0.7048125267028809f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.439881324768066f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -41.0646858215332f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7085670828819275f, 0.0f, 0.0f, -0.7056434154510498f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &park,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 4.668251991271973f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 21.579273223876953f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7004075646400452f, 0.0f, 0.0f, -0.7137432098388672f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &path,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.10000000149011612f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -5.993139743804932f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -5.2844085693359375f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 4.11979866027832f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -17.962167739868164f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9743093848228455f, 0.0f, 0.0f, 0.22521378099918365f },
    /* SCALE        */ (float[3]){ 0.959849f * scaleMultiplier, 0.959849f * scaleMultiplier, 0.959849f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -11.498758316040039f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -30.328250885009766f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9791783690452576f, 0.0f, 0.0f, -0.20300182700157166f },
    /* SCALE        */ (float[3]){ 1.260104f * scaleMultiplier, 1.260104f * scaleMultiplier, 1.260104f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.85298728942871f * xPositionMultiplier, -0.23659467697143555f * yPositionMultiplier, 6.694875240325928f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.858501434326172f * xPositionMultiplier, -0.23659467697143555f * yPositionMultiplier, 15.532757759094238f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -9.418587684631348f * xPositionMultiplier, -0.23659515380859375f * yPositionMultiplier, 19.96548080444336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -4.371138828673793e-08f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[25] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 25,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -5.0024027824401855f * xPositionMultiplier, -0.23659467697143555f * yPositionMultiplier, 24.387178421020508f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[26] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 26,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -7.401448726654053f * xPositionMultiplier, 5.116583824157715f * yPositionMultiplier, 19.044544219970703f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[27] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 27,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -26.877174377441406f * xPositionMultiplier, 5.3670477867126465f * yPositionMultiplier, 16.057445526123047f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.790477f * scaleMultiplier, 0.790477f * scaleMultiplier, 0.790477f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[28] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 28,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.412105560302734f * xPositionMultiplier, 6.026771068572998f * yPositionMultiplier, 10.471080780029297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.724125f * scaleMultiplier, 0.724125f * scaleMultiplier, 0.724125f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[29] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 29,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.305335998535156f * xPositionMultiplier, 5.324122428894043f * yPositionMultiplier, 5.120994567871094f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.719931f * scaleMultiplier, 0.460360f * scaleMultiplier, 0.719931f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[30] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 30,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -4.152491569519043f * xPositionMultiplier, 5.235229015350342f * yPositionMultiplier, 26.09110450744629f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.624187f * scaleMultiplier, 0.624187f * scaleMultiplier, 0.624187f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[31] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 31,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -18.256473541259766f * xPositionMultiplier, -0.23659515380859375f * yPositionMultiplier, 19.96548080444336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -4.371138828673793e-08f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[32] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 32,
    /* MODEL DATA   */ &tree_line,
    /* POSITION     */ (float[3]){ -27.0943603515625f * xPositionMultiplier, -0.23659539222717285f * yPositionMultiplier, 19.96548080444336f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -4.371138828673793e-08f, -0.0f, 0.0f, 1.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[33] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 33,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -3.979196786880493f * xPositionMultiplier, 5.235229015350342f * yPositionMultiplier, 22.29166030883789f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.624187f * scaleMultiplier, 0.624187f * scaleMultiplier, 0.624187f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[34] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 34,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -13.352758407592773f * xPositionMultiplier, 5.5504560470581055f * yPositionMultiplier, 19.55707550048828f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[35] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 35,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.311267852783203f * xPositionMultiplier, 4.875235080718994f * yPositionMultiplier, 19.328107833862305f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[36] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 36,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -22.753318786621094f * xPositionMultiplier, 5.7529296875f * yPositionMultiplier, 19.793954849243164f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[37] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 37,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -27.265586853027344f * xPositionMultiplier, 5.521531105041504f * yPositionMultiplier, 19.55707550048828f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier, 0.766016f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[38] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 38,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.272844314575195f * xPositionMultiplier, 6.1017608642578125f * yPositionMultiplier, 5.5238938331604f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.941242f * scaleMultiplier, 0.601877f * scaleMultiplier, 0.941242f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[39] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 39,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -28.6632080078125f * xPositionMultiplier, 6.852243423461914f * yPositionMultiplier, 12.754007339477539f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 1.114472f * scaleMultiplier, 0.712649f * scaleMultiplier, 1.114472f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[40] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 40,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -19.311267852783203f * xPositionMultiplier, 4.595937728881836f * yPositionMultiplier, 22.048616409301758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.252550f * scaleMultiplier, 1.252550f * scaleMultiplier, 1.252550f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[41] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 41,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -11.027078628540039f * xPositionMultiplier, 3.7045235633850098f * yPositionMultiplier, 22.68726348876953f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.252550f * scaleMultiplier, 1.252550f * scaleMultiplier, 1.252550f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[42] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 42,
    /* MODEL DATA   */ &tree_tops,
    /* POSITION     */ (float[3]){ -5.997624397277832f * xPositionMultiplier, 5.809389114379883f * yPositionMultiplier, 27.31039047241211f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7071067690849304f, 0.0f, 0.0f, 0.7071067690849304f },
    /* SCALE        */ (float[3]){ 0.763397f * scaleMultiplier, 0.763397f * scaleMultiplier, 0.763397f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[43] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 43,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -6.544979095458984f * xPositionMultiplier, 1.0269938707351685f * yPositionMultiplier, 11.806673049926758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9643753170967102f, 0.0f, 0.0f, 0.2645378112792969f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  Park.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);
	entities[0] = createFeather(&actors[43]);

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
}

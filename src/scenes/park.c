/*
* PARK SCENE
* GENERATED ON 2026-08-17
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
  .actorCount = 71,
  .modelCount = 9,
  .entityCount = 2,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData simple_tree = setupModel("rom:/simple_tree.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData park = setupModel("rom:/park.t3dm");
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = rock_post.model;
	models[1] = simple_tree.model;
	models[2] = iron_trim.model;
	models[3] = stump.model;
	models[4] = feather.model;
	models[5] = plant.model;
	models[6] = park.model;
	models[7] = two_cube.model;
	models[8] = rock_wall_long.model;


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
    /* POSITION     */ (float[3]){ 7.480812072753906f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 14.89657211303711f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[1] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 1,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -7.428676605224609f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 14.742865562438965f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[2] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 2,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -11.527505874633789f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 3.7784976959228516f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9886044263839722f, 0.0f, 0.0f, 0.15053683519363403f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[3] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 3,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -15.113981246948242f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -10.464933395385742f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9994298815727234f, 0.0f, 0.0f, -0.03376397490501404f },
    /* SCALE        */ (float[3]){ 1.965580f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -12.962096214294434f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -25.067012786865234f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9994298815727234f, 0.0f, 0.0f, -0.03376397490501404f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -14.70409870147705f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -39.566619873046875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9994298815727234f, 0.0f, 0.0f, -0.03376397490501404f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -14.24298095703125f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -53.758819580078125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.946178674697876f, 0.0f, 0.0f, -0.32364481687545776f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -0.10202136635780334f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -56.1668815612793f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999873161315918f, 0.0f, 0.0f, 0.01592656970024109f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 14.448820114135742f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -54.78352737426758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9993737936019897f, 0.0f, 0.0f, -0.03538474440574646f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 29.25583839416504f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -54.83476257324219f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9981727004051208f, 0.0f, 0.0f, 0.060425255447626114f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 43.857913970947266f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -56.320587158203125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9984671473503113f, 0.0f, 0.0f, -0.055346883833408356f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.36116027832031f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -46.58586883544922f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999781847000122f, 0.0f, 0.0f, 0.006596360355615616f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.77104187011719f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -31.8300838470459f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999781847000122f, 0.0f, 0.0f, 0.006596360355615616f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.56610107421875f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -17.074298858642578f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999781847000122f, 0.0f, 0.0f, 0.006596360355615616f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.56610107421875f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -1.8061609268188477f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9999781847000122f, 0.0f, 0.0f, 0.006596360355615616f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 53.5413932800293f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 5.6742024421691895f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9438890814781189f, 0.0f, 0.0f, 0.3302624821662903f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[16] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 16,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 39.2979621887207f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 5.879144191741943f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9997867941856384f, 0.0f, 0.0f, -0.02064812183380127f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[17] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 17,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 24.542179107666016f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 6.289026737213135f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9984845519065857f, 0.0f, 0.0f, 0.055032506585121155f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[18] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 18,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 10.247514724731445f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 9.260677337646484f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9606006741523743f, 0.0f, 0.0f, 0.27793222665786743f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 24.644649505615234f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -8.72293472290039f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9807119369506836f, 0.0f, 0.0f, 0.19545897841453552f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 10.145044326782227f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -11.899527549743652f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8928400874137878f, 0.0f, 0.0f, 0.45037421584129333f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 4.7140960693359375f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -25.425662994384766f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7577306628227234f, 0.0f, 0.0f, 0.6525676250457764f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 18.188995361328125f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -28.192373275756836f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7312203049659729f, 0.0f, 0.0f, 0.6821416020393372f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 30.63918685913086f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -22.044130325317383f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6456533670425415f, 0.0f, 0.0f, 0.7636308670043945f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 7.14186429977417f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -55.54412841796875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.998299777507782f, 0.0f, 0.0f, -0.058288998901844025f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[25] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 25,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 21.90817642211914f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -54.699066162109375f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[26] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 26,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 36.67449188232422f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -55.633079528808594f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9986717104911804f, 0.0f, 0.0f, 0.051525890827178955f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[27] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 27,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 49.394866943359375f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -51.941497802734375f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9304214119911194f, 0.0f, 0.0f, -0.3664914667606354f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[28] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 28,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 54.55418395996094f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -39.265594482421875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7161940932273865f, 0.0f, 0.0f, -0.6979012489318848f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[29] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 29,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 54.64313507080078f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -24.32137107849121f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017704248428345f, 0.0f, 0.0f, -0.7124032974243164f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[30] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 30,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 54.42074966430664f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -9.332670211791992f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017704248428345f, 0.0f, 0.0f, -0.7124032974243164f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[31] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 31,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 53.66464614868164f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 5.433644771575928f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6688429117202759f, 0.0f, 0.0f, -0.7434039115905762f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[32] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 32,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 46.45939636230469f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 5.83393669128418f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630225598812103f, 0.0f, 0.0f, -0.9999536871910095f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[33] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 33,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 31.78203582763672f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 6.056321144104004f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630225598812103f, 0.0f, 0.0f, -0.9999536871910095f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[34] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 34,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 17.193628311157227f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 7.790918350219727f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.10348289459943771f, 0.0f, 0.0f, -0.994631290435791f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[35] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 35,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 8.120349884033203f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 16.063613891601562f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6170953512191772f, 0.0f, 0.0f, -0.7868885397911072f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[36] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 36,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -7.482126235961914f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -55.17052459716797f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9975467324256897f, 0.0f, 0.0f, 0.07000428438186646f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[37] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 37,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -14.634005546569824f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -46.844459533691406f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.709876537322998f, 0.0f, 0.0f, 0.7043261528015137f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[38] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 38,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -13.780050277709961f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -32.167091369628906f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6510016918182373f, 0.0f, 0.0f, 0.7590761780738831f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[39] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 39,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -13.993539810180664f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -17.86333465576172f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7680333256721497f, 0.0f, 0.0f, 0.6404088735580444f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[40] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 40,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -13.299700736999512f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -3.452834129333496f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6104980111122131f, 0.0f, 0.0f, 0.7920169830322266f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[41] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 41,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -9.456899642944336f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 11.064412117004395f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6104980111122131f, 0.0f, 0.0f, 0.7920169830322266f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[42] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 42,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 0.06238555908203125f * xPositionMultiplier, -3.175865411758423f * yPositionMultiplier, 14.966093063354492f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.00261794775724411f, 0.0f, 0.0f, 0.999996542930603f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[43] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 43,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 17.266822814941406f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -10.142097473144531f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9940452575683594f, 0.0f, 0.0f, -0.1089690774679184f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[44] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 44,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 7.092582702636719f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -18.632831573486328f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8286614418029785f, 0.0f, 0.0f, -0.559750497341156f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[45] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 45,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 28.09982681274414f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -15.265815734863281f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8374608755111694f, 0.0f, 0.0f, 0.5464975237846375f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[46] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 46,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 24.291606903076172f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -25.22453498840332f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.21036379039287567f, 0.0f, 0.0f, -0.9776234030723572f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[47] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 47,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 11.189528465270996f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -26.981237411499023f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.09243129193782806f, 0.0f, 0.0f, -0.9957192540168762f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[48] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 48,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 4.16594123840332f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.563694953918457f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[49] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 49,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.7689685225486755f * yPositionMultiplier, 9.78023624420166f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8598006367683411f, 0.0f, 0.0f, -0.5106298327445984f },
    /* SCALE        */ (float[3]){ 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[50] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 50,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.2794775664806366f * yPositionMultiplier, 9.78023624420166f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.4781578779220581f, 0.0f, -0.0f, -0.8782739043235779f },
    /* SCALE        */ (float[3]){ 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[51] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 51,
    /* MODEL DATA   */ &plant,
    /* POSITION     */ (float[3]){ -7.292577743530273f * xPositionMultiplier, 0.0f * yPositionMultiplier, 11.149275779724121f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9415283799171448f, 0.0f, 0.0f, -0.33693361282348633f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[52] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 52,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ 16.94610023498535f * xPositionMultiplier, -0.23953300714492798f * yPositionMultiplier, -38.35631561279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.73820561170578f, 0.0f, 0.0f, 0.6745758056640625f },
    /* SCALE        */ (float[3]){ 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[53] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 53,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ 38.109256744384766f * xPositionMultiplier, -0.22443218529224396f * yPositionMultiplier, -25.409765243530273f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.9844614863395691f, 0.0f, 0.0f, 0.17560051381587982f },
    /* SCALE        */ (float[3]){ 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[54] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 54,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ -6.542078018188477f * xPositionMultiplier, -0.22218048572540283f * yPositionMultiplier, 11.813546180725098f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ -0.6982279419898987f, 0.0f, 0.0f, 0.715875506401062f },
    /* SCALE        */ (float[3]){ 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[55] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 55,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 6.997776508331299f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -8.652423858642578f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[56] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 56,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 6.2234015464782715f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -12.941268920898438f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9466575980186462f, 0.0f, 0.0f, -0.3222412168979645f },
    /* SCALE        */ (float[3]){ 1.323871f * scaleMultiplier, 1.323871f * scaleMultiplier, 1.323871f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[57] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 57,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 12.299264907836914f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -9.248096466064453f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9743094444274902f, 0.0f, 0.0f, 0.22521376609802246f },
    /* SCALE        */ (float[3]){ 0.959849f * scaleMultiplier, 0.959849f * scaleMultiplier, 0.959849f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[58] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 58,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -9.885505676269531f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -46.01963806152344f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[59] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 59,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -10.31640338897705f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -50.87441635131836f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9058878421783447f, 0.0f, 0.0f, 0.42351770401000977f },
    /* SCALE        */ (float[3]){ 1.681488f * scaleMultiplier, 1.681488f * scaleMultiplier, 1.681488f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[60] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 60,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -3.393314838409424f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -50.07007598876953f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.906578004360199f, 0.0f, 0.0f, -0.42203831672668457f },
    /* SCALE        */ (float[3]){ 1.268234f * scaleMultiplier, 1.268234f * scaleMultiplier, 1.268234f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[61] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 61,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ -6.093606948852539f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -53.287445068359375f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 0.912126f * scaleMultiplier, 0.912126f * scaleMultiplier, 0.912126f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[62] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 62,
    /* MODEL DATA   */ &two_cube,
    /* POSITION     */ (float[3]){ -7.9592485427856445f * xPositionMultiplier, -0.19999998807907104f * yPositionMultiplier, -4.003936767578125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ true,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[63] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 63,
    /* MODEL DATA   */ &park,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[64] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 64,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 0.06436766684055328f * xPositionMultiplier, 0.8241345882415771f * yPositionMultiplier, 14.606243133544922f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[65] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 65,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -9.074127197265625f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 10.963645935058594f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6104980111122131f, 0.0f, 0.0f, 0.7920169830322266f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[66] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 66,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -12.916929244995117f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -3.553600311279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6104980111122131f, 0.0f, 0.0f, 0.7920169830322266f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[67] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 67,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -13.604174613952637f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -17.792184829711914f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7680333256721497f, 0.0f, 0.0f, 0.6404088735580444f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[68] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 68,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -13.388860702514648f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -32.22740936279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6510016918182373f, 0.0f, 0.0f, 0.7590761780738831f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

	// Entity Actors
	actors[69] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 69,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -6.544979095458984f * xPositionMultiplier, 1.0269938707351685f * yPositionMultiplier, 11.806673049926758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9643753170967102f, 0.0f, 0.0f, 0.26453784108161926f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[70] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 70,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ 39.782440185546875f * xPositionMultiplier, -0.04391884803771973f * yPositionMultiplier, -26.373685836791992f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.972390353679657f, 0.0f, 0.0f, 0.23336024582386017f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );

  Park.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);
	entities[0] = createFeather(&actors[69]);
	entities[1] = createFeather(&actors[70]);

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

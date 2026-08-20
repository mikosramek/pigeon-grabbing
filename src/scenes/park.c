/*
* PARK SCENE
* GENERATED ON 2026-08-20
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
  .actorCount = 91,
  .modelCount = 9,
  .entityCount = 2,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData park = setupModel("rom:/park.t3dm");
	ModelData simple_tree = setupModel("rom:/simple_tree.t3dm");
	ModelData path = setupModel("rom:/path.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData iron_trim = setupModel("rom:/iron_trim.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = rock_wall_long.model;
	models[1] = plant.model;
	models[2] = park.model;
	models[3] = simple_tree.model;
	models[4] = path.model;
	models[5] = rock_post.model;
	models[6] = iron_trim.model;
	models[7] = feather.model;
	models[8] = stump.model;


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
    /* ROTATION     */ (float[4]){ 0.9994298219680786f, 0.0f, 0.0f, -0.03376397863030434f },
    /* SCALE        */ (float[3]){ 1.965580f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[4] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 4,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -12.962096214294434f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -25.067012786865234f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9994298219680786f, 0.0f, 0.0f, -0.03376397863030434f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[5] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 5,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -14.70409870147705f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -39.566619873046875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9994298219680786f, 0.0f, 0.0f, -0.03376397863030434f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[6] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 6,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -14.24298095703125f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -53.758819580078125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9461786150932312f, 0.0f, 0.0f, -0.32364481687545776f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[7] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 7,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ -0.10202136635780334f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -56.1668815612793f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999873161315918f, 0.0f, 0.0f, 0.01592656783759594f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[8] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 8,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 14.448820114135742f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -54.78352737426758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999373733997345f, 0.0f, 0.0f, -0.03538474813103676f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[9] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 9,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 29.25583839416504f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -54.83476257324219f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9981727004051208f, 0.0f, 0.0f, 0.06042527034878731f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[10] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 10,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 43.857913970947266f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -56.320587158203125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.998467206954956f, 0.0f, 0.0f, -0.05534689500927925f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[11] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 11,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.36116027832031f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -46.58586883544922f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999978244304657f, 0.0f, 0.0f, 0.006596361752599478f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[12] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 12,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.77104187011719f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -31.8300838470459f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999978244304657f, 0.0f, 0.0f, 0.006596361752599478f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[13] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 13,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.56610107421875f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -17.074298858642578f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999978244304657f, 0.0f, 0.0f, 0.006596361752599478f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[14] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 14,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 54.56610107421875f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, -1.8061609268188477f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.999978244304657f, 0.0f, 0.0f, 0.006596361752599478f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[15] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 15,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 53.5413932800293f * xPositionMultiplier, -4.87770938873291f * yPositionMultiplier, 5.6742024421691895f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9438891410827637f, 0.0f, 0.0f, 0.33026254177093506f },
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
    /* ROTATION     */ (float[4]){ 0.9606006741523743f, 0.0f, 0.0f, 0.2779322862625122f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[19] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 19,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 24.644649505615234f * xPositionMultiplier, -3.754135847091675f * yPositionMultiplier, -8.72293472290039f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9807118773460388f, 0.0f, 0.0f, 0.19545899331569672f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[20] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 20,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 10.145044326782227f * xPositionMultiplier, -3.754135847091675f * yPositionMultiplier, -11.899527549743652f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8928399085998535f, 0.0f, 0.0f, 0.45037415623664856f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[21] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 21,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 4.7140960693359375f * xPositionMultiplier, -3.754135847091675f * yPositionMultiplier, -25.425662994384766f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7577305436134338f, 0.0f, 0.0f, 0.6525675654411316f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[22] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 22,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 18.188995361328125f * xPositionMultiplier, -3.754135847091675f * yPositionMultiplier, -28.192373275756836f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7312201857566833f, 0.0f, 0.0f, 0.6821415424346924f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[23] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 23,
    /* MODEL DATA   */ &rock_post,
    /* POSITION     */ (float[3]){ 30.63918685913086f * xPositionMultiplier, -3.754135847091675f * yPositionMultiplier, -22.044130325317383f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6456531882286072f, 0.0f, 0.0f, 0.763630747795105f },
    /* SCALE        */ (float[3]){ 1.965581f * scaleMultiplier, 1.965581f * scaleMultiplier, 1.304025f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[24] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 24,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 7.14186429977417f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -55.54412841796875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.998299777507782f, 0.0f, 0.0f, -0.05828900262713432f },
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
    /* ROTATION     */ (float[4]){ 0.9986716508865356f, 0.0f, 0.0f, 0.051525890827178955f },
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
    /* ROTATION     */ (float[4]){ 0.7161939740180969f, 0.0f, 0.0f, -0.6979012489318848f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[29] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 29,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 54.64313507080078f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -24.32137107849121f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017703652381897f, 0.0f, 0.0f, -0.7124032378196716f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[30] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 30,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 54.42074966430664f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -9.332670211791992f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017703652381897f, 0.0f, 0.0f, -0.7124032378196716f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[31] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 31,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 53.66464614868164f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 5.433644771575928f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6688427925109863f, 0.0f, 0.0f, -0.7434038519859314f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[32] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 32,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 46.45939636230469f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 5.83393669128418f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630248881876469f, 0.0f, 0.0f, -0.9999536275863647f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[33] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 33,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 31.78203582763672f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 6.056321144104004f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630248881876469f, 0.0f, 0.0f, -0.9999536275863647f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[34] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 34,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 17.193628311157227f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 7.790918350219727f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.1034829393029213f, 0.0f, 0.0f, -0.9946312308311462f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[35] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 35,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 8.120349884033203f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 16.063613891601562f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6170953512191772f, 0.0f, 0.0f, -0.7868884205818176f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[36] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 36,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -7.482126235961914f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -55.17052459716797f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9975466728210449f, 0.0f, 0.0f, 0.07000429183244705f },
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
    /* ROTATION     */ (float[4]){ 0.6510016322135925f, 0.0f, 0.0f, 0.7590762972831726f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[39] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 39,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -13.993539810180664f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -17.86333465576172f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7680337429046631f, 0.0f, 0.0f, 0.6404093503952026f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[40] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 40,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -13.299700736999512f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, -3.452834129333496f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920175790786743f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[41] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 41,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ -9.456899642944336f * xPositionMultiplier, -2.5307424068450928f * yPositionMultiplier, 11.064412117004395f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920175790786743f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[42] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 42,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 0.06238555908203125f * xPositionMultiplier, -3.175865411758423f * yPositionMultiplier, 14.966093063354492f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.0026179084088653326f, 0.0f, 0.0f, 0.9999966025352478f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[43] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 43,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 17.266822814941406f * xPositionMultiplier, -1.4071688652038574f * yPositionMultiplier, -10.142097473144531f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9940451383590698f, 0.0f, 0.0f, -0.1089690700173378f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[44] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 44,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 7.092582702636719f * xPositionMultiplier, -1.4071688652038574f * yPositionMultiplier, -18.632831573486328f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8286612033843994f, 0.0f, 0.0f, -0.5597504377365112f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[45] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 45,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 28.09982681274414f * xPositionMultiplier, -1.4071688652038574f * yPositionMultiplier, -15.265815734863281f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8374607563018799f, 0.0f, 0.0f, 0.5464974641799927f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[46] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 46,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 24.291606903076172f * xPositionMultiplier, -1.4071688652038574f * yPositionMultiplier, -25.22453498840332f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.21036377549171448f, 0.0f, -0.0f, 0.9776231646537781f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[47] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 47,
    /* MODEL DATA   */ &rock_wall_long,
    /* POSITION     */ (float[3]){ 11.189528465270996f * xPositionMultiplier, -1.4071688652038574f * yPositionMultiplier, -26.981237411499023f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.09243122488260269f, 0.0f, 0.0f, -0.9957190752029419f },
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
    /* ROTATION     */ (float[4]){ 0.9415283799171448f, 0.0f, 0.0f, -0.3369336724281311f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[52] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 52,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ 16.94610023498535f * xPositionMultiplier, -0.23953300714492798f * yPositionMultiplier, -38.35631561279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7382055521011353f, 0.0f, 0.0f, 0.6745758056640625f },
    /* SCALE        */ (float[3]){ 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[53] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 53,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ 38.109256744384766f * xPositionMultiplier, -0.22443218529224396f * yPositionMultiplier, -25.409765243530273f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9844614863395691f, 0.0f, -0.0f, -0.17560051381587982f },
    /* SCALE        */ (float[3]){ 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[54] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 54,
    /* MODEL DATA   */ &stump,
    /* POSITION     */ (float[3]){ -6.542078018188477f * xPositionMultiplier, -0.22218048572540283f * yPositionMultiplier, 11.813546180725098f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6982279419898987f, 0.0f, -0.0f, -0.715875506401062f },
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
    /* ROTATION     */ (float[4]){ 0.9466575980186462f, 0.0f, 0.0f, -0.32224124670028687f },
    /* SCALE        */ (float[3]){ 1.323871f * scaleMultiplier, 1.323871f * scaleMultiplier, 1.323871f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[57] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 57,
    /* MODEL DATA   */ &simple_tree,
    /* POSITION     */ (float[3]){ 12.299264907836914f * xPositionMultiplier, -0.4248204827308655f * yPositionMultiplier, -9.248096466064453f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9743093848228455f, 0.0f, 0.0f, 0.22521378099918365f },
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
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 0.06436766684055328f * xPositionMultiplier, 0.8241345882415771f * yPositionMultiplier, 14.606243133544922f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[63] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 63,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -9.074127197265625f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 10.963645935058594f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920175790786743f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[64] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 64,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -12.916929244995117f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -3.553600311279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920175790786743f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[65] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 65,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -13.604174613952637f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -17.792184829711914f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7680337429046631f, 0.0f, 0.0f, 0.6404093503952026f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[66] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 66,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -13.388860702514648f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -32.22740936279297f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6510016322135925f, 0.0f, 0.0f, 0.7590762972831726f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[67] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 67,
    /* MODEL DATA   */ &park,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );
	actors[68] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 68,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 17.181072235107422f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -9.755684852600098f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9940451383590698f, 0.0f, 0.0f, -0.1089690700173378f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[69] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 69,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 24.454410552978516f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -25.585315704345703f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.21036377549171448f, 0.0f, -0.0f, 0.9776231646537781f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[70] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 70,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 24.454410552978516f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -25.585315704345703f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.21036377549171448f, 0.0f, -0.0f, 0.9776231646537781f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[71] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 71,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 28.462129592895508f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -15.106428146362305f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8374607563018799f, 0.0f, 0.0f, 0.5464974641799927f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[72] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 72,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 11.44449234008789f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -27.14590835571289f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.09243122488260269f, 0.0f, 0.0f, -0.9957190752029419f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[73] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 73,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 6.725391387939453f * xPositionMultiplier, 2.5928311347961426f * yPositionMultiplier, -18.48505210876465f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.8286612033843994f, 0.0f, 0.0f, -0.5597504377365112f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[74] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 74,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -14.238204956054688f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -46.84135055541992f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.709876537322998f, 0.0f, 0.0f, 0.7043261528015137f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[75] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 75,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ -7.426846504211426f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -54.77859115600586f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9975466728210449f, 0.0f, 0.0f, 0.07000429183244705f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[76] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 76,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 7.095798015594482f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -55.151004791259766f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.998299777507782f, 0.0f, 0.0f, -0.05828900262713432f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[77] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 77,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 21.908174514770508f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -54.303253173828125f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[78] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 78,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 36.71522521972656f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -55.2393684387207f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9986716508865356f, 0.0f, 0.0f, 0.051525890827178955f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[79] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 79,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 49.12492752075195f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -51.652015686035156f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9304214119911194f, 0.0f, 0.0f, -0.3664914667606354f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[80] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 80,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 54.158504486083984f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -39.25535583496094f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7161939740180969f, 0.0f, 0.0f, -0.6979012489318848f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[81] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 81,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 54.24736404418945f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -24.32732582092285f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017703652381897f, 0.0f, 0.0f, -0.7124032378196716f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[82] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 82,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 54.02497863769531f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, -9.338623046875f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.7017703652381897f, 0.0f, 0.0f, -0.7124032378196716f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[83] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 83,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 53.271034240722656f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 5.391964912414551f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6688427925109863f, 0.0f, 0.0f, -0.7434038519859314f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[84] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 84,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 46.45177459716797f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 5.438197135925293f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630248881876469f, 0.0f, 0.0f, -0.9999536275863647f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[85] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 85,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 31.7744140625f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 5.660581588745117f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.009630248881876469f, 0.0f, 0.0f, -0.9999536275863647f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[86] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 86,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 17.11214828491211f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 7.4035820960998535f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.1034829393029213f, 0.0f, 0.0f, -0.9946312308311462f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[87] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 87,
    /* MODEL DATA   */ &iron_trim,
    /* POSITION     */ (float[3]){ 7.73594856262207f * xPositionMultiplier, 1.4692575931549072f * yPositionMultiplier, 15.969256401062012f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.6170953512191772f, 0.0f, 0.0f, -0.7868884205818176f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[88] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 88,
    /* MODEL DATA   */ &path,
    /* POSITION     */ (float[3]){ 0.0f * xPositionMultiplier, 0.10000000149011612f * yPositionMultiplier, -0.0f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ true,
    FB_COUNT
  );

	// Entity Actors
	actors[89] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 89,
    /* MODEL DATA   */ &feather,
    /* POSITION     */ (float[3]){ -6.544979095458984f * xPositionMultiplier, 1.0269938707351685f * yPositionMultiplier, 11.806673049926758f * zPositionMultiplier },
    /* ROTATION     */ (float[4]){ 0.9643753170967102f, 0.0f, 0.0f, 0.2645378112792969f },
    /* SCALE        */ (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier},
    /* SKIP         */ false,
    /* SKIP CULLING */ false,
    FB_COUNT
  );
	actors[90] = setupActor(
    /* ACTOR INDEX  */ startingIndex + 90,
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
	entities[0] = createFeather(&actors[89]);
	entities[1] = createFeather(&actors[90]);

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

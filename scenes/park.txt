/*
* PARK SCENE
* GENERATED ON 2026-08-15
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
  .actorCount = 57,
  .modelCount = 12,
  .entityCount = 2,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData tree_one = setupModel("rom:/tree_one.t3dm");
	ModelData park_ground_se = setupModel("rom:/park_ground_se.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData park_ground_ne = setupModel("rom:/park_ground_ne.t3dm");
	ModelData park_ground_nw = setupModel("rom:/park_ground_nw.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData gate = setupModel("rom:/gate.t3dm");
	ModelData park_ground_sw = setupModel("rom:/park_ground_sw.t3dm");
	ModelData water = setupModel("rom:/water.t3dm");
	ModelData rock_wall_long = setupModel("rom:/rock_wall_long.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = rock_post.model;
	models[1] = tree_one.model;
	models[2] = park_ground_se.model;
	models[3] = stump.model;
	models[4] = feather.model;
	models[5] = park_ground_ne.model;
	models[6] = park_ground_nw.model;
	models[7] = plant.model;
	models[8] = gate.model;
	models[9] = park_ground_sw.model;
	models[10] = water.model;
	models[11] = rock_wall_long.model;


  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * Park.actorCount);
	actors[0] = setupActor(startingIndex + 0, &rock_post, (float[3]){ -12.74846363067627f * xPositionMultiplier, 0.0f * yPositionMultiplier, -34.51417922973633f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, &rock_post, (float[3]){ -14.77660846710205f * xPositionMultiplier, 0.0f * yPositionMultiplier, -49.01951217651367f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, &rock_post, (float[3]){ -14.460744857788086f * xPositionMultiplier, 0.0f * yPositionMultiplier, -63.51874542236328f * zPositionMultiplier }, (float[4]){ 0.9652637839317322f, 0.0f, 0.0f, -0.2612771689891815f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, &rock_post, (float[3]){ -0.3886050581932068f * xPositionMultiplier, 0.0f * yPositionMultiplier, -65.92804718017578f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, &rock_post, (float[3]){ 14.443933486938477f * xPositionMultiplier, 0.0f * yPositionMultiplier, -64.47518157958984f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, &rock_post, (float[3]){ 29.3232364654541f * xPositionMultiplier, 0.0f * yPositionMultiplier, -64.51636505126953f * zPositionMultiplier }, (float[4]){ 0.9984856247901917f, 0.0f, 0.0f, 0.055013395845890045f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, &rock_post, (float[3]){ 44.10371017456055f * xPositionMultiplier, 0.0f * yPositionMultiplier, -66.38768768310547f * zPositionMultiplier }, (float[4]){ 0.9248772859573364f, 0.0f, 0.0f, -0.3802657127380371f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, &rock_post, (float[3]){ 54.32564163208008f * xPositionMultiplier, 0.0f * yPositionMultiplier, -56.380859375f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, &rock_post, (float[3]){ 54.699493408203125f * xPositionMultiplier, 0.0f * yPositionMultiplier, -41.37141799926758f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[9] = setupActor(startingIndex + 9, &rock_post, (float[3]){ 54.508426666259766f * xPositionMultiplier, 0.0f * yPositionMultiplier, -26.44434928894043f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[10] = setupActor(startingIndex + 10, &rock_post, (float[3]){ 54.37863540649414f * xPositionMultiplier, 0.0f * yPositionMultiplier, -11.60651683807373f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[11] = setupActor(startingIndex + 11, &rock_post, (float[3]){ 53.69890213012695f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.081996440887451f * zPositionMultiplier }, (float[4]){ 0.9290283918380737f, 0.0f, 0.0f, 0.37000852823257446f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[12] = setupActor(startingIndex + 12, &rock_post, (float[3]){ 39.07659149169922f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.8168389797210693f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[13] = setupActor(startingIndex + 13, &rock_post, (float[3]){ 24.304401397705078f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.5005080699920654f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[14] = setupActor(startingIndex + 14, &rock_post, (float[3]){ 9.860005378723145f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.5203547477722168f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[15] = setupActor(startingIndex + 15, &rock_post, (float[3]){ 8.035958290100098f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.393545150756836f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[16] = setupActor(startingIndex + 16, &rock_post, (float[3]){ -8.148222923278809f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.357208251953125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[17] = setupActor(startingIndex + 17, &rock_post, (float[3]){ -11.437328338623047f * xPositionMultiplier, 0.0f * yPositionMultiplier, -5.857387065887451f * zPositionMultiplier }, (float[4]){ 0.9867523908615112f, 0.0f, 0.0f, 0.16223371028900146f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[18] = setupActor(startingIndex + 18, &rock_post, (float[3]){ -14.953042984008789f * xPositionMultiplier, 0.0f * yPositionMultiplier, -20.2988338470459f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[19] = setupActor(startingIndex + 19, &rock_wall_long, (float[3]){ 7.14186429977417f * xPositionMultiplier, 0.0f * yPositionMultiplier, -65.29713439941406f * zPositionMultiplier }, (float[4]){ 0.998299777507782f, 0.0f, 0.0f, -0.058288998901844025f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[20] = setupActor(startingIndex + 20, &rock_wall_long, (float[3]){ 21.90817642211914f * xPositionMultiplier, 0.0f * yPositionMultiplier, -64.45207214355469f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[21] = setupActor(startingIndex + 21, &rock_wall_long, (float[3]){ 36.67449188232422f * xPositionMultiplier, 0.0f * yPositionMultiplier, -65.3860855102539f * zPositionMultiplier }, (float[4]){ 0.9986717104911804f, 0.0f, 0.0f, 0.051525890827178955f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[22] = setupActor(startingIndex + 22, &rock_wall_long, (float[3]){ 49.394866943359375f * xPositionMultiplier, 0.0f * yPositionMultiplier, -61.69450378417969f * zPositionMultiplier }, (float[4]){ 0.9304214119911194f, 0.0f, 0.0f, -0.3664914667606354f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[23] = setupActor(startingIndex + 23, &rock_wall_long, (float[3]){ 54.55418395996094f * xPositionMultiplier, 0.0f * yPositionMultiplier, -49.01860427856445f * zPositionMultiplier }, (float[4]){ 0.7161940932273865f, 0.0f, 0.0f, -0.6979012489318848f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[24] = setupActor(startingIndex + 24, &rock_wall_long, (float[3]){ 54.64313507080078f * xPositionMultiplier, 0.0f * yPositionMultiplier, -34.074378967285156f * zPositionMultiplier }, (float[4]){ 0.7017704248428345f, 0.0f, 0.0f, -0.7124032974243164f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[25] = setupActor(startingIndex + 25, &rock_wall_long, (float[3]){ 54.42074966430664f * xPositionMultiplier, 0.0f * yPositionMultiplier, -19.085678100585938f * zPositionMultiplier }, (float[4]){ 0.7017704248428345f, 0.0f, 0.0f, -0.7124032974243164f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[26] = setupActor(startingIndex + 26, &rock_wall_long, (float[3]){ 53.66464614868164f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.319363117218018f * zPositionMultiplier }, (float[4]){ 0.6688429117202759f, 0.0f, 0.0f, -0.7434039115905762f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[27] = setupActor(startingIndex + 27, &rock_wall_long, (float[3]){ 46.45939636230469f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.9190711975097656f * zPositionMultiplier }, (float[4]){ 0.009630225598812103f, 0.0f, 0.0f, -0.9999536871910095f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[28] = setupActor(startingIndex + 28, &rock_wall_long, (float[3]){ 31.78203582763672f * xPositionMultiplier, 0.0f * yPositionMultiplier, -3.6966869831085205f * zPositionMultiplier }, (float[4]){ 0.009630225598812103f, 0.0f, 0.0f, -0.9999536871910095f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[29] = setupActor(startingIndex + 29, &rock_wall_long, (float[3]){ 17.193628311157227f * xPositionMultiplier, 0.0f * yPositionMultiplier, -1.9620894193649292f * zPositionMultiplier }, (float[4]){ 0.10348289459943771f, 0.0f, 0.0f, -0.994631290435791f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[30] = setupActor(startingIndex + 30, &rock_wall_long, (float[3]){ 8.120349884033203f * xPositionMultiplier, 0.0f * yPositionMultiplier, 6.310606002807617f * zPositionMultiplier }, (float[4]){ 0.6170953512191772f, 0.0f, 0.0f, -0.7868885397911072f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[31] = setupActor(startingIndex + 31, &rock_wall_long, (float[3]){ -7.482126235961914f * xPositionMultiplier, 0.0f * yPositionMultiplier, -64.92353057861328f * zPositionMultiplier }, (float[4]){ 0.9975467324256897f, 0.0f, 0.0f, 0.07000428438186646f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[32] = setupActor(startingIndex + 32, &rock_wall_long, (float[3]){ -14.634005546569824f * xPositionMultiplier, 0.0f * yPositionMultiplier, -56.59746551513672f * zPositionMultiplier }, (float[4]){ 0.709876537322998f, 0.0f, 0.0f, 0.7043261528015137f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[33] = setupActor(startingIndex + 33, &rock_wall_long, (float[3]){ -13.780050277709961f * xPositionMultiplier, 0.0f * yPositionMultiplier, -41.920101165771484f * zPositionMultiplier }, (float[4]){ 0.6510016918182373f, 0.0f, 0.0f, 0.7590761780738831f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[34] = setupActor(startingIndex + 34, &rock_wall_long, (float[3]){ -13.993539810180664f * xPositionMultiplier, 0.0f * yPositionMultiplier, -27.616342544555664f * zPositionMultiplier }, (float[4]){ 0.7575236558914185f, 0.0f, 0.0f, 0.6528075933456421f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[35] = setupActor(startingIndex + 35, &rock_wall_long, (float[3]){ -13.299700736999512f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.205842018127441f * zPositionMultiplier }, (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920174598693848f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[36] = setupActor(startingIndex + 36, &rock_wall_long, (float[3]){ -9.456899642944336f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.3114042282104492f * zPositionMultiplier }, (float[4]){ 0.610498309135437f, 0.0f, 0.0f, 0.7920174598693848f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[37] = setupActor(startingIndex + 37, &park_ground_ne, (float[3]){ 37.040748596191406f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[38] = setupActor(startingIndex + 38, &park_ground_nw, (float[3]){ -2.9592504501342773f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[39] = setupActor(startingIndex + 39, &park_ground_se, (float[3]){ 37.04075241088867f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003935813903809f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[40] = setupActor(startingIndex + 40, &park_ground_sw, (float[3]){ -2.9592485427856445f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[41] = setupActor(startingIndex + 41, &water, (float[3]){ 31.22661590576172f * xPositionMultiplier, -0.808538556098938f * yPositionMultiplier, -45.11707305908203f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier}, FB_COUNT);
	actors[42] = setupActor(startingIndex + 42, &plant, (float[3]){ 4.16594123840332f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.810686707496643f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[43] = setupActor(startingIndex + 43, &plant, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.7689685225486755f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[4]){ 0.8598006367683411f, 0.0f, 0.0f, -0.5106298327445984f }, (float[3]){ 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier}, FB_COUNT);
	actors[44] = setupActor(startingIndex + 44, &plant, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.2794775664806366f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[4]){ 0.4781578779220581f, 0.0f, -0.0f, -0.8782739043235779f }, (float[3]){ 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier}, FB_COUNT);
	actors[45] = setupActor(startingIndex + 45, &plant, (float[3]){ -8.3148775100708f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.667122483253479f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[46] = setupActor(startingIndex + 46, &stump, (float[3]){ 16.94610023498535f * xPositionMultiplier, -0.23953300714492798f * yPositionMultiplier, -48.10932159423828f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier}, FB_COUNT);
	actors[47] = setupActor(startingIndex + 47, &stump, (float[3]){ 38.109256744384766f * xPositionMultiplier, -0.22443218529224396f * yPositionMultiplier, -35.16277313232422f * zPositionMultiplier }, (float[4]){ -0.9844614863395691f, 0.0f, 0.0f, 0.17560051381587982f }, (float[3]){ 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier}, FB_COUNT);
	actors[48] = setupActor(startingIndex + 48, &stump, (float[3]){ -8.413824081420898f * xPositionMultiplier, -0.22218048572540283f * yPositionMultiplier, 0.4646286964416504f * zPositionMultiplier }, (float[4]){ -0.6982279419898987f, 0.0f, 0.0f, 0.715875506401062f }, (float[3]){ 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier}, FB_COUNT);
	actors[49] = setupActor(startingIndex + 49, &gate, (float[3]){ 0.033120155334472656f * xPositionMultiplier, -0.5225858688354492f * yPositionMultiplier, 5.499626159667969f * zPositionMultiplier }, (float[4]){ 0.999998152256012f, 0.0f, 0.0f, 0.0019165462581440806f }, (float[3]){ 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier}, FB_COUNT);
	actors[50] = setupActor(startingIndex + 50, &tree_one, (float[3]){ 2.1000072956085205f * xPositionMultiplier, -0.1134377121925354f * yPositionMultiplier, -18.10460662841797f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[51] = setupActor(startingIndex + 51, &tree_one, (float[3]){ 33.416961669921875f * xPositionMultiplier, -0.1134377121925354f * yPositionMultiplier, -13.458985328674316f * zPositionMultiplier }, (float[4]){ 0.19537891447544098f, 0.0f, 0.0f, -0.9807278513908386f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[52] = setupActor(startingIndex + 52, &tree_one, (float[3]){ 44.33235168457031f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -13.050040245056152f * zPositionMultiplier }, (float[4]){ 0.763994574546814f, 0.0f, 0.0f, -0.6452227234840393f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[53] = setupActor(startingIndex + 53, &tree_one, (float[3]){ -1.8505887985229492f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -49.5045051574707f * zPositionMultiplier }, (float[4]){ 0.9494704008102417f, 0.0f, 0.0f, 0.31385692954063416f }, (float[3]){ 1.251489f * scaleMultiplier, 1.251489f * scaleMultiplier, 1.251489f * scaleMultiplier}, FB_COUNT);
	actors[54] = setupActor(startingIndex + 54, &tree_one, (float[3]){ 37.644168853759766f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -0.8111222982406616f * zPositionMultiplier }, (float[4]){ 0.2532416880130768f, 0.0f, 0.0f, -0.9674031138420105f }, (float[3]){ 0.737890f * scaleMultiplier, 0.737890f * scaleMultiplier, 0.737890f * scaleMultiplier}, FB_COUNT);

	// Entity Actors
	actors[55] = setupActor(startingIndex + 55, &feather, (float[3]){ -8.416725158691406f * xPositionMultiplier, 1.0269938707351685f * yPositionMultiplier, 0.45775556564331055f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[56] = setupActor(startingIndex + 56, &feather, (float[3]){ 39.782440185546875f * xPositionMultiplier, -0.04391884803771973f * yPositionMultiplier, -36.12669372558594f * zPositionMultiplier }, (float[4]){ 0.972390353679657f, 0.0f, 0.0f, 0.23336024582386017f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);

  Park.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);
	entities[0] = createFeather(&actors[55]);
	entities[1] = createFeather(&actors[56]);

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

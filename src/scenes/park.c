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
  .actorCount = 75,
  .modelCount = 12,
  .entityCount = 2,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData park_ground_se = setupModel("rom:/park_ground_se.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData rock_wall = setupModel("rom:/rock_wall.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData park_ground_ne = setupModel("rom:/park_ground_ne.t3dm");
	ModelData park_ground_nw = setupModel("rom:/park_ground_nw.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData gate = setupModel("rom:/gate.t3dm");
	ModelData park_ground_sw = setupModel("rom:/park_ground_sw.t3dm");
	ModelData water = setupModel("rom:/water.t3dm");
	ModelData tree_one = setupModel("rom:/tree_one.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = rock_post.model;
	models[1] = park_ground_se.model;
	models[2] = stump.model;
	models[3] = rock_wall.model;
	models[4] = feather.model;
	models[5] = park_ground_ne.model;
	models[6] = park_ground_nw.model;
	models[7] = plant.model;
	models[8] = gate.model;
	models[9] = park_ground_sw.model;
	models[10] = water.model;
	models[11] = tree_one.model;


  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * Park.actorCount);
	actors[0] = setupActor(startingIndex + 0, &rock_post, (float[3]){ -11.84113597869873f * xPositionMultiplier, 0.0f * yPositionMultiplier, -39.157562255859375f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, &rock_post, (float[3]){ -11.84113597869873f * xPositionMultiplier, 0.0f * yPositionMultiplier, -46.99136734008789f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, &rock_post, (float[3]){ -7.255494117736816f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.05778884887695f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, &rock_post, (float[3]){ 0.10064029693603516f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.29662322998047f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, &rock_post, (float[3]){ 7.647842884063721f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.723419189453125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, &rock_post, (float[3]){ 14.621840476989746f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.866722106933594f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, &rock_post, (float[3]){ 22.073509216308594f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.81895446777344f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, &rock_post, (float[3]){ 29.381874084472656f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.866722106933594f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, &rock_post, (float[3]){ 36.7857780456543f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.91448974609375f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[9] = setupActor(startingIndex + 9, &rock_post, (float[3]){ 42.1834602355957f * xPositionMultiplier, 0.0f * yPositionMultiplier, -47.7078742980957f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[10] = setupActor(startingIndex + 10, &rock_post, (float[3]){ 43.091033935546875f * xPositionMultiplier, 0.0f * yPositionMultiplier, -40.30397415161133f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[11] = setupActor(startingIndex + 11, &rock_post, (float[3]){ 42.899967193603516f * xPositionMultiplier, 0.0f * yPositionMultiplier, -32.80453872680664f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[12] = setupActor(startingIndex + 12, &rock_post, (float[3]){ 42.94773483276367f * xPositionMultiplier, 0.0f * yPositionMultiplier, -25.54393768310547f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[13] = setupActor(startingIndex + 13, &rock_post, (float[3]){ 43.234336853027344f * xPositionMultiplier, 0.0f * yPositionMultiplier, -17.853435516357422f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[14] = setupActor(startingIndex + 14, &rock_post, (float[3]){ 39.46073532104492f * xPositionMultiplier, 0.0f * yPositionMultiplier, -11.357109069824219f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[15] = setupActor(startingIndex + 15, &rock_post, (float[3]){ 39.07859802246094f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.000974655151367f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[16] = setupActor(startingIndex + 16, &rock_post, (float[3]){ 32.438968658447266f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.6572780609130859f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[17] = setupActor(startingIndex + 17, &rock_post, (float[3]){ 24.84400177001953f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.03630638122558594f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[18] = setupActor(startingIndex + 18, &rock_post, (float[3]){ 17.010196685791016f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.6095123291015625f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[19] = setupActor(startingIndex + 19, &rock_post, (float[3]){ 9.504190444946289f * xPositionMultiplier, 0.0f * yPositionMultiplier, -1.1875076293945312f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[20] = setupActor(startingIndex + 20, &rock_post, (float[3]){ -14.23180103302002f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.4102535247802734f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[21] = setupActor(startingIndex + 21, &rock_post, (float[3]){ 8.035958290100098f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.393545150756836f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[22] = setupActor(startingIndex + 22, &rock_post, (float[3]){ -8.148222923278809f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.357208251953125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[23] = setupActor(startingIndex + 23, &rock_post, (float[3]){ -11.117094993591309f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.096103668212891f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[24] = setupActor(startingIndex + 24, &rock_post, (float[3]){ -11.366734504699707f * xPositionMultiplier, 0.0f * yPositionMultiplier, -11.609495162963867f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[25] = setupActor(startingIndex + 25, &rock_post, (float[3]){ -5.822478294372559f * xPositionMultiplier, 0.0f * yPositionMultiplier, -17.08916473388672f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[26] = setupActor(startingIndex + 26, &rock_post, (float[3]){ -9.882681846618652f * xPositionMultiplier, 0.0f * yPositionMultiplier, -23.39442253112793f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[27] = setupActor(startingIndex + 27, &rock_post, (float[3]){ -11.029091835021973f * xPositionMultiplier, 0.0f * yPositionMultiplier, -31.037158966064453f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[28] = setupActor(startingIndex + 28, &rock_wall, (float[3]){ -10.551423072814941f * xPositionMultiplier, 0.0f * yPositionMultiplier, -26.7858829498291f * zPositionMultiplier }, (float[4]){ 0.7411267757415771f, 0.0f, -0.0f, -0.6713650822639465f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[29] = setupActor(startingIndex + 29, &rock_wall, (float[3]){ -11.868271827697754f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -43.175228118896484f * zPositionMultiplier }, (float[4]){ 0.7071067094802856f, 0.0f, 0.0f, 0.7071068286895752f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[30] = setupActor(startingIndex + 30, &rock_wall, (float[3]){ -9.527684211730957f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -50.053688049316406f * zPositionMultiplier }, (float[4]){ 0.894957959651947f, 0.0f, 0.0f, 0.4461505115032196f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[31] = setupActor(startingIndex + 31, &rock_wall, (float[3]){ -3.556796073913574f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -53.30185317993164f * zPositionMultiplier }, (float[4]){ 0.9997909665107727f, 0.0f, 0.0f, 0.020444553345441818f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[32] = setupActor(startingIndex + 32, &rock_wall, (float[3]){ 3.847105026245117f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.96748352050781f * zPositionMultiplier }, (float[4]){ 0.9992640018463135f, 0.0f, -0.0f, -0.03836013749241829f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[33] = setupActor(startingIndex + 33, &rock_wall, (float[3]){ 11.012170791625977f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.72864532470703f * zPositionMultiplier }, (float[4]){ 0.9999999403953552f, 0.0f, -0.0f, -0.0004142523102927953f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[34] = setupActor(startingIndex + 34, &rock_wall, (float[3]){ 18.463838577270508f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.77641296386719f * zPositionMultiplier }, (float[4]){ 0.9999999403953552f, 0.0f, -0.0f, -0.0004142523102927953f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[35] = setupActor(startingIndex + 35, &rock_wall, (float[3]){ 25.867740631103516f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.824180603027344f * zPositionMultiplier }, (float[4]){ 0.9999999403953552f, 0.0f, -0.0f, -0.0004142523102927953f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[36] = setupActor(startingIndex + 36, &rock_wall, (float[3]){ 33.08057403564453f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.824180603027344f * zPositionMultiplier }, (float[4]){ 0.9999999403953552f, 0.0f, -0.0f, -0.0004142523102927953f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[37] = setupActor(startingIndex + 37, &rock_wall, (float[3]){ 39.52913284301758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -50.340293884277344f * zPositionMultiplier }, (float[4]){ -0.9170722365379333f, 0.0f, 0.0f, 0.3987210690975189f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[38] = setupActor(startingIndex + 38, &rock_wall, (float[3]){ 42.6817626953125f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -44.082801818847656f * zPositionMultiplier }, (float[4]){ -0.7412481307983398f, 0.0f, 0.0f, 0.6712310910224915f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[39] = setupActor(startingIndex + 39, &rock_wall, (float[3]){ 43.01613235473633f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -36.4400634765625f * zPositionMultiplier }, (float[4]){ 0.6942821145057678f, 0.0f, -0.0f, -0.719702959060669f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[40] = setupActor(startingIndex + 40, &rock_wall, (float[3]){ 42.96836471557617f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -29.08393096923828f * zPositionMultiplier }, (float[4]){ 0.7159797549247742f, 0.0f, -0.0f, -0.6981210112571716f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[41] = setupActor(startingIndex + 41, &rock_wall, (float[3]){ 43.1594352722168f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -21.680030822753906f * zPositionMultiplier }, (float[4]){ 0.7159797549247742f, 0.0f, -0.0f, -0.6981210112571716f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[42] = setupActor(startingIndex + 42, &rock_wall, (float[3]){ 41.4398193359375f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -14.658266067504883f * zPositionMultiplier }, (float[4]){ 0.5003765225410461f, 0.0f, -0.0f, -0.8658078908920288f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[43] = setupActor(startingIndex + 43, &rock_wall, (float[3]){ 39.52913284301758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -7.397666931152344f * zPositionMultiplier }, (float[4]){ 0.7296417355537415f, 0.0f, -0.0f, -0.6838296055793762f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[44] = setupActor(startingIndex + 44, &rock_wall, (float[3]){ 35.80329895019531f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -2.382120132446289f * zPositionMultiplier }, (float[4]){ 0.2301143854856491f, 0.0f, -0.0f, -0.9731636047363281f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[45] = setupActor(startingIndex + 45, &rock_wall, (float[3]){ 28.68600082397461f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.3759021759033203f * zPositionMultiplier }, (float[4]){ 0.05672884359955788f, 0.0f, -0.0f, -0.9983896017074585f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[46] = setupActor(startingIndex + 46, &rock_wall, (float[3]){ 20.947731018066406f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.23260116577148438f * zPositionMultiplier }, (float[4]){ -0.03523935750126839f, -0.0f, 0.0f, -0.9993789196014404f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[47] = setupActor(startingIndex + 47, &rock_wall, (float[3]){ 13.055208206176758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.9276180267333984f * zPositionMultiplier }, (float[4]){ -0.04621449112892151f, -0.0f, 0.0f, -0.9989315271377563f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[48] = setupActor(startingIndex + 48, &rock_wall, (float[3]){ -10.888960838317871f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, 3.656097412109375f * zPositionMultiplier }, (float[4]){ 0.9575249552726746f, 0.0f, -0.0f, -0.28835049271583557f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[49] = setupActor(startingIndex + 49, &rock_wall, (float[3]){ 8.863658905029297f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, 2.0257930755615234f * zPositionMultiplier }, (float[4]){ -0.7807829976081848f, -0.0f, 0.0f, -0.62480229139328f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[50] = setupActor(startingIndex + 50, &rock_wall, (float[3]){ -12.92292308807373f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -1.4586963653564453f * zPositionMultiplier }, (float[4]){ 0.47438761591911316f, 0.0f, -0.0f, -0.8803160786628723f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[51] = setupActor(startingIndex + 51, &rock_wall, (float[3]){ -11.221283912658691f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -7.981821060180664f * zPositionMultiplier }, (float[4]){ 0.7233689427375793f, 0.0f, -0.0f, -0.6904616951942444f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[52] = setupActor(startingIndex + 52, &rock_wall, (float[3]){ -8.526209831237793f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -14.558762550354004f * zPositionMultiplier }, (float[4]){ 0.3946171700954437f, 0.0f, -0.0f, -0.9188456535339355f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[53] = setupActor(startingIndex + 53, &rock_wall, (float[3]){ -7.664765357971191f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -20.008182525634766f * zPositionMultiplier }, (float[4]){ 0.85918790102005f, 0.0f, -0.0f, -0.5116601586341858f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[54] = setupActor(startingIndex + 54, &rock_wall, (float[3]){ -11.31569766998291f * xPositionMultiplier, 0.0f * yPositionMultiplier, -35.192893981933594f * zPositionMultiplier }, (float[4]){ 0.7411267757415771f, 0.0f, -0.0f, -0.6713650822639465f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[55] = setupActor(startingIndex + 55, &park_ground_ne, (float[3]){ 37.040748596191406f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[56] = setupActor(startingIndex + 56, &park_ground_nw, (float[3]){ -2.9592504501342773f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[57] = setupActor(startingIndex + 57, &park_ground_se, (float[3]){ 37.04075241088867f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003935813903809f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[58] = setupActor(startingIndex + 58, &park_ground_sw, (float[3]){ -2.9592485427856445f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003936767578125f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[59] = setupActor(startingIndex + 59, &water, (float[3]){ 31.22661590576172f * xPositionMultiplier, -0.808538556098938f * yPositionMultiplier, -45.11707305908203f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier}, FB_COUNT);
	actors[60] = setupActor(startingIndex + 60, &plant, (float[3]){ 4.16594123840332f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.810686707496643f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[61] = setupActor(startingIndex + 61, &plant, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.7689685225486755f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[4]){ 0.8598006367683411f, 0.0f, 0.0f, -0.5106298327445984f }, (float[3]){ 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier}, FB_COUNT);
	actors[62] = setupActor(startingIndex + 62, &plant, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.2794775664806366f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[4]){ 0.4781578779220581f, 0.0f, -0.0f, -0.8782739043235779f }, (float[3]){ 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier}, FB_COUNT);
	actors[63] = setupActor(startingIndex + 63, &plant, (float[3]){ -8.3148775100708f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.667122483253479f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[64] = setupActor(startingIndex + 64, &stump, (float[3]){ 16.94610023498535f * xPositionMultiplier, -0.23953300714492798f * yPositionMultiplier, -48.10932159423828f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier, 0.858223f * scaleMultiplier}, FB_COUNT);
	actors[65] = setupActor(startingIndex + 65, &stump, (float[3]){ 38.109256744384766f * xPositionMultiplier, -0.22443218529224396f * yPositionMultiplier, -35.16277313232422f * zPositionMultiplier }, (float[4]){ -0.9844614863395691f, 0.0f, 0.0f, 0.17560051381587982f }, (float[3]){ 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier, 0.674030f * scaleMultiplier}, FB_COUNT);
	actors[66] = setupActor(startingIndex + 66, &stump, (float[3]){ -8.413824081420898f * xPositionMultiplier, -0.22218048572540283f * yPositionMultiplier, 0.4646286964416504f * zPositionMultiplier }, (float[4]){ -0.6982279419898987f, 0.0f, 0.0f, 0.715875506401062f }, (float[3]){ 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier, 0.636081f * scaleMultiplier}, FB_COUNT);
	actors[67] = setupActor(startingIndex + 67, &gate, (float[3]){ 0.033120155334472656f * xPositionMultiplier, -0.5225858688354492f * yPositionMultiplier, 5.499626159667969f * zPositionMultiplier }, (float[4]){ 0.999998152256012f, 0.0f, 0.0f, 0.0019165462581440806f }, (float[3]){ 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier}, FB_COUNT);
	actors[68] = setupActor(startingIndex + 68, &tree_one, (float[3]){ 2.1000072956085205f * xPositionMultiplier, -0.1134377121925354f * yPositionMultiplier, -18.10460662841797f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[69] = setupActor(startingIndex + 69, &tree_one, (float[3]){ 33.416961669921875f * xPositionMultiplier, -0.1134377121925354f * yPositionMultiplier, -13.458985328674316f * zPositionMultiplier }, (float[4]){ 0.19537891447544098f, 0.0f, 0.0f, -0.9807278513908386f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[70] = setupActor(startingIndex + 70, &tree_one, (float[3]){ 44.33235168457031f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -13.050040245056152f * zPositionMultiplier }, (float[4]){ 0.763994574546814f, 0.0f, 0.0f, -0.6452227234840393f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[71] = setupActor(startingIndex + 71, &tree_one, (float[3]){ -1.8505887985229492f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -49.5045051574707f * zPositionMultiplier }, (float[4]){ 0.9494704008102417f, 0.0f, 0.0f, 0.31385692954063416f }, (float[3]){ 1.251489f * scaleMultiplier, 1.251489f * scaleMultiplier, 1.251489f * scaleMultiplier}, FB_COUNT);
	actors[72] = setupActor(startingIndex + 72, &tree_one, (float[3]){ 37.644168853759766f * xPositionMultiplier, 0.33988791704177856f * yPositionMultiplier, -0.8111222982406616f * zPositionMultiplier }, (float[4]){ 0.2532416880130768f, 0.0f, 0.0f, -0.9674031138420105f }, (float[3]){ 0.737890f * scaleMultiplier, 0.737890f * scaleMultiplier, 0.737890f * scaleMultiplier}, FB_COUNT);

	// Entity Actors
	actors[73] = setupActor(startingIndex + 73, &feather, (float[3]){ -8.416725158691406f * xPositionMultiplier, 1.0269938707351685f * yPositionMultiplier, 0.45775556564331055f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[74] = setupActor(startingIndex + 74, &feather, (float[3]){ 39.782440185546875f * xPositionMultiplier, -0.04391884803771973f * yPositionMultiplier, -36.12669372558594f * zPositionMultiplier }, (float[4]){ 0.972390353679657f, 0.0f, 0.0f, 0.23336024582386017f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);

  Park.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);
	entities[0] = createFeather(&actors[73]);
	entities[1] = createFeather(&actors[74]);

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

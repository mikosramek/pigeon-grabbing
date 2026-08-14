/*
* PARK SCENE
* GENERATED ON 2026-08-12
*/
// INCLUDES
#include "park.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"
#include "../entities/feather.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene Park = (Scene) {
  .name = "Park",
  .actorCount = 71,
  .modelCount = 12,
	.entityCount = 1,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
	ModelData gate = setupModel("rom:/gate.t3dm");
	ModelData plant = setupModel("rom:/plant.t3dm");
	ModelData park_ground_se = setupModel("rom:/park_ground_se.t3dm");
	ModelData feather = setupModel("rom:/feather.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData park_ground_nw = setupModel("rom:/park_ground_nw.t3dm");
	ModelData rock_wall = setupModel("rom:/rock_wall.t3dm");
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData park_ground_ne = setupModel("rom:/park_ground_ne.t3dm");
	ModelData park_ground_sw = setupModel("rom:/park_ground_sw.t3dm");
	ModelData water = setupModel("rom:/water.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Park.modelCount);
	models[0] = gate.model;
	models[1] = plant.model;
	models[2] = park_ground_se.model;
	models[3] = feather.model;
	models[4] = rock_post.model;
	models[5] = park_ground_nw.model;
	models[6] = rock_wall.model;
	models[7] = two_cube.model;
	models[8] = park_ground_ne.model;
	models[9] = park_ground_sw.model;
	models[10] = water.model;
	models[11] = stump.model;


  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * Park.actorCount);
	// Static Actors
	actors[0] = setupActor(startingIndex + 0, stump.dpl, (float[3]){ 16.94610023498535f * xPositionMultiplier, -0.7952721118927002f * yPositionMultiplier, -48.10932159423828f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.434630f * scaleMultiplier, 1.434630f * scaleMultiplier, 1.434630f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, stump.dpl, (float[3]){ 38.109256744384766f * xPositionMultiplier, -0.22443218529224396f * yPositionMultiplier, -35.16277313232422f * zPositionMultiplier }, (float[3]){ 0.0f, -5.930153846740723f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, rock_wall.dpl, (float[3]){ -10.551423072814941f * xPositionMultiplier, 0.0f * yPositionMultiplier, -26.7858829498291f * zPositionMultiplier }, (float[3]){ 0.0f, 1.4720983505249023f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, rock_wall.dpl, (float[3]){ -11.868271827697754f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -43.175228118896484f * zPositionMultiplier }, (float[3]){ 0.0f, -1.5707964897155762f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, rock_wall.dpl, (float[3]){ -9.527684211730957f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -50.053688049316406f * zPositionMultiplier }, (float[3]){ 0.0f, -0.9249187707901001f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, rock_wall.dpl, (float[3]){ -3.556796073913574f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -53.30185317993164f * zPositionMultiplier }, (float[3]){ 0.0f, -0.04089195653796196f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, rock_wall.dpl, (float[3]){ 3.847105026245117f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.96748352050781f * zPositionMultiplier }, (float[3]){ 0.0f, 0.076739102602005f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, rock_wall.dpl, (float[3]){ 11.012170791625977f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.72864532470703f * zPositionMultiplier }, (float[3]){ 0.0f, 0.0008285046205855906f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, rock_wall.dpl, (float[3]){ 18.463838577270508f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.77641296386719f * zPositionMultiplier }, (float[3]){ 0.0f, 0.0008285046205855906f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[9] = setupActor(startingIndex + 9, rock_wall.dpl, (float[3]){ 25.867740631103516f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.824180603027344f * zPositionMultiplier }, (float[3]){ 0.0f, 0.0008285046205855906f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[10] = setupActor(startingIndex + 10, rock_wall.dpl, (float[3]){ 33.08057403564453f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -52.824180603027344f * zPositionMultiplier }, (float[3]){ 0.0f, 0.0008285046205855906f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[11] = setupActor(startingIndex + 11, rock_wall.dpl, (float[3]){ 39.52913284301758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -50.340293884277344f * zPositionMultiplier }, (float[3]){ 0.0f, -5.462941646575928f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[12] = setupActor(startingIndex + 12, rock_wall.dpl, (float[3]){ 42.6817626953125f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -44.082801818847656f * zPositionMultiplier }, (float[3]){ 0.0f, -4.811448574066162f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[13] = setupActor(startingIndex + 13, rock_wall.dpl, (float[3]){ 43.01613235473633f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -36.4400634765625f * zPositionMultiplier }, (float[3]){ 0.0f, 1.6067488193511963f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[14] = setupActor(startingIndex + 14, rock_wall.dpl, (float[3]){ 42.96836471557617f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -29.08393096923828f * zPositionMultiplier }, (float[3]){ 0.0f, 1.5455396175384521f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[15] = setupActor(startingIndex + 15, rock_wall.dpl, (float[3]){ 43.1594352722168f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -21.680030822753906f * zPositionMultiplier }, (float[3]){ 0.0f, 1.5455396175384521f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[16] = setupActor(startingIndex + 16, rock_wall.dpl, (float[3]){ 41.4398193359375f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -14.658266067504883f * zPositionMultiplier }, (float[3]){ 0.0f, 2.0935254096984863f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[17] = setupActor(startingIndex + 17, rock_wall.dpl, (float[3]){ 39.52913284301758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -7.397666931152344f * zPositionMultiplier }, (float[3]){ 0.0f, 1.505996823310852f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[18] = setupActor(startingIndex + 18, rock_wall.dpl, (float[3]){ 35.80329895019531f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -2.382120132446289f * zPositionMultiplier }, (float[3]){ 0.0f, 2.6772022247314453f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[19] = setupActor(startingIndex + 19, rock_wall.dpl, (float[3]){ 28.68600082397461f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.3759021759033203f * zPositionMultiplier }, (float[3]){ 0.0f, 3.028074026107788f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[20] = setupActor(startingIndex + 20, rock_wall.dpl, (float[3]){ 20.947731018066406f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.23260116577148438f * zPositionMultiplier }, (float[3]){ 0.0f, 3.2120859622955322f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[21] = setupActor(startingIndex + 21, rock_wall.dpl, (float[3]){ 13.055208206176758f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -0.9276180267333984f * zPositionMultiplier }, (float[3]){ 0.0f, 3.2340545654296875f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[22] = setupActor(startingIndex + 22, rock_wall.dpl, (float[3]){ -10.888960838317871f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, 3.656097412109375f * zPositionMultiplier }, (float[3]){ 0.0f, 0.5850074291229248f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[23] = setupActor(startingIndex + 23, rock_wall.dpl, (float[3]){ 8.863658905029297f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, 2.0257930755615234f * zPositionMultiplier }, (float[3]){ 0.0f, 4.933428764343262f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[24] = setupActor(startingIndex + 24, rock_wall.dpl, (float[3]){ -12.92292308807373f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -1.4586963653564453f * zPositionMultiplier }, (float[3]){ 0.0f, 2.1530561447143555f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[25] = setupActor(startingIndex + 25, rock_wall.dpl, (float[3]){ -11.221283912658691f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -7.981821060180664f * zPositionMultiplier }, (float[3]){ 0.0f, 1.5242542028427124f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[26] = setupActor(startingIndex + 26, rock_wall.dpl, (float[3]){ -8.526209831237793f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -14.558762550354004f * zPositionMultiplier }, (float[3]){ 0.0f, 2.3302903175354004f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[27] = setupActor(startingIndex + 27, rock_wall.dpl, (float[3]){ -7.664765357971191f * xPositionMultiplier, 1.6689300537109375e-06f * yPositionMultiplier, -20.008182525634766f * zPositionMultiplier }, (float[3]){ 0.0f, 1.0742318630218506f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[28] = setupActor(startingIndex + 28, rock_wall.dpl, (float[3]){ -11.31569766998291f * xPositionMultiplier, 0.0f * yPositionMultiplier, -35.192893981933594f * zPositionMultiplier }, (float[3]){ 0.0f, 1.4720983505249023f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[29] = setupActor(startingIndex + 29, rock_post.dpl, (float[3]){ -11.84113597869873f * xPositionMultiplier, 0.0f * yPositionMultiplier, -39.157562255859375f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[30] = setupActor(startingIndex + 30, rock_post.dpl, (float[3]){ -11.84113597869873f * xPositionMultiplier, 0.0f * yPositionMultiplier, -46.99136734008789f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[31] = setupActor(startingIndex + 31, rock_post.dpl, (float[3]){ -7.255494117736816f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.05778884887695f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[32] = setupActor(startingIndex + 32, rock_post.dpl, (float[3]){ 0.10064029693603516f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.29662322998047f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[33] = setupActor(startingIndex + 33, rock_post.dpl, (float[3]){ 7.647842884063721f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.723419189453125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[34] = setupActor(startingIndex + 34, rock_post.dpl, (float[3]){ 14.621840476989746f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.866722106933594f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[35] = setupActor(startingIndex + 35, rock_post.dpl, (float[3]){ 22.073509216308594f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.81895446777344f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[36] = setupActor(startingIndex + 36, rock_post.dpl, (float[3]){ 29.381874084472656f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.866722106933594f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[37] = setupActor(startingIndex + 37, rock_post.dpl, (float[3]){ 36.7857780456543f * xPositionMultiplier, 0.0f * yPositionMultiplier, -52.91448974609375f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[38] = setupActor(startingIndex + 38, rock_post.dpl, (float[3]){ 42.1834602355957f * xPositionMultiplier, 0.0f * yPositionMultiplier, -47.7078742980957f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[39] = setupActor(startingIndex + 39, rock_post.dpl, (float[3]){ 43.091033935546875f * xPositionMultiplier, 0.0f * yPositionMultiplier, -40.30397415161133f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[40] = setupActor(startingIndex + 40, rock_post.dpl, (float[3]){ 42.899967193603516f * xPositionMultiplier, 0.0f * yPositionMultiplier, -32.80453872680664f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[41] = setupActor(startingIndex + 41, rock_post.dpl, (float[3]){ 42.94773483276367f * xPositionMultiplier, 0.0f * yPositionMultiplier, -25.54393768310547f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[42] = setupActor(startingIndex + 42, rock_post.dpl, (float[3]){ 43.234336853027344f * xPositionMultiplier, 0.0f * yPositionMultiplier, -17.853435516357422f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[43] = setupActor(startingIndex + 43, rock_post.dpl, (float[3]){ 39.46073532104492f * xPositionMultiplier, 0.0f * yPositionMultiplier, -11.357109069824219f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[44] = setupActor(startingIndex + 44, rock_post.dpl, (float[3]){ 39.07859802246094f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.000974655151367f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[45] = setupActor(startingIndex + 45, rock_post.dpl, (float[3]){ 32.438968658447266f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.6572780609130859f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[46] = setupActor(startingIndex + 46, rock_post.dpl, (float[3]){ 24.84400177001953f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.03630638122558594f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[47] = setupActor(startingIndex + 47, rock_post.dpl, (float[3]){ 17.010196685791016f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.6095123291015625f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[48] = setupActor(startingIndex + 48, rock_post.dpl, (float[3]){ 9.504190444946289f * xPositionMultiplier, 0.0f * yPositionMultiplier, -1.1875076293945312f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[49] = setupActor(startingIndex + 49, rock_post.dpl, (float[3]){ -14.23180103302002f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.4102535247802734f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[50] = setupActor(startingIndex + 50, rock_post.dpl, (float[3]){ 8.035958290100098f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.393545150756836f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[51] = setupActor(startingIndex + 51, rock_post.dpl, (float[3]){ -8.148222923278809f * xPositionMultiplier, 0.0f * yPositionMultiplier, 5.357208251953125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[52] = setupActor(startingIndex + 52, rock_post.dpl, (float[3]){ -11.117094993591309f * xPositionMultiplier, 0.0f * yPositionMultiplier, -4.096103668212891f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[53] = setupActor(startingIndex + 53, rock_post.dpl, (float[3]){ -11.366734504699707f * xPositionMultiplier, 0.0f * yPositionMultiplier, -11.609495162963867f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[54] = setupActor(startingIndex + 54, rock_post.dpl, (float[3]){ -5.822478294372559f * xPositionMultiplier, 0.0f * yPositionMultiplier, -17.08916473388672f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[55] = setupActor(startingIndex + 55, rock_post.dpl, (float[3]){ -9.882681846618652f * xPositionMultiplier, 0.0f * yPositionMultiplier, -23.39442253112793f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[56] = setupActor(startingIndex + 56, rock_post.dpl, (float[3]){ -11.029091835021973f * xPositionMultiplier, 0.0f * yPositionMultiplier, -31.037158966064453f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier, 1.371359f * scaleMultiplier}, FB_COUNT);
	actors[57] = setupActor(startingIndex + 57, gate.dpl, (float[3]){ 0.033120155334472656f * xPositionMultiplier, -0.5225858688354492f * yPositionMultiplier, 5.499626159667969f * zPositionMultiplier }, (float[3]){ 0.0f, -0.003833094844594598f, 0.0f }, (float[3]){ 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier, 1.119576f * scaleMultiplier}, FB_COUNT);
	actors[58] = setupActor(startingIndex + 58, water.dpl, (float[3]){ 31.22661590576172f * xPositionMultiplier, -0.808538556098938f * yPositionMultiplier, -45.11707305908203f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier, 1.150065f * scaleMultiplier}, FB_COUNT);
	actors[59] = setupActor(startingIndex + 59, park_ground_ne.dpl, (float[3]){ 37.040748596191406f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[60] = setupActor(startingIndex + 60, park_ground_nw.dpl, (float[3]){ -2.9592504501342773f * xPositionMultiplier, 0.0f * yPositionMultiplier, -53.003936767578125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[61] = setupActor(startingIndex + 61, park_ground_se.dpl, (float[3]){ 37.04075241088867f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003935813903809f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[62] = setupActor(startingIndex + 62, park_ground_sw.dpl, (float[3]){ -2.9592485427856445f * xPositionMultiplier, 0.0f * yPositionMultiplier, -13.003936767578125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[63] = setupActor(startingIndex + 63, two_cube.dpl, (float[3]){ -7.9592485427856445f * xPositionMultiplier, -0.19999998807907104f * yPositionMultiplier, -28.003936767578125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[64] = setupActor(startingIndex + 64, plant.dpl, (float[3]){ 4.16594123840332f * xPositionMultiplier, 0.0f * yPositionMultiplier, 1.810686707496643f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[65] = setupActor(startingIndex + 65, plant.dpl, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.7689685225486755f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[3]){ 0.0f, 1.0718343257904053f, -0.0f }, (float[3]){ 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier, 1.965320f * scaleMultiplier}, FB_COUNT);
	actors[66] = setupActor(startingIndex + 66, stump.dpl, (float[3]){ -9.475857734680176f * xPositionMultiplier, -0.18513472378253937f * yPositionMultiplier, 0.5029782056808472f * zPositionMultiplier }, (float[3]){ 0.0f, -4.6874308586120605f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[67] = setupActor(startingIndex + 67, plant.dpl, (float[3]){ 6.112770080566406f * xPositionMultiplier, -0.2794775664806366f * yPositionMultiplier, 0.027228355407714844f * zPositionMultiplier }, (float[3]){ 0.0f, 2.1444804668426514f, 0.0f }, (float[3]){ 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier, 1.726222f * scaleMultiplier}, FB_COUNT);
	actors[68] = setupActor(startingIndex + 68, plant.dpl, (float[3]){ -8.3148775100708f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.667122483253479f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	actors[69] = setupActor(startingIndex + 69, two_cube.dpl, (float[3]){ -7.9592485427856445f * xPositionMultiplier, -0.19999998807907104f * yPositionMultiplier, -4.003936767578125f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);
	
	// Entity Actors
	actors[70] = setupActor(startingIndex + 70, feather.dpl, (float[3]){ -9.483036041259766f * xPositionMultiplier, 2.288670539855957f * yPositionMultiplier, 0.505250871181488f * zPositionMultiplier }, (float[3]){ 0.0f, -0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, FB_COUNT);

  Park.actors = actors;

	// Entities
	struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Park.entityCount);
	entities[0] = createFeather(&actors[70]);

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

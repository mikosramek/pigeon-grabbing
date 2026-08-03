#include "park.h"


#include "../utils/pigeon_utils.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// SCENE
#define PARK_ACTOR_COUNT 8

static Scene Park = (Scene) {
  .actorCount = PARK_ACTOR_COUNT
};


Scene createPark(uint32_t FB_COUNT) {
  ModelData ground = setupModel("rom:/ground.t3dm");
  ModelData stump = setupModel("rom:/stump.t3dm");
  ModelData stump2 = setupModel("rom:/stump2.t3dm");
  ModelData hedge = setupModel("rom:/hedge.t3dm");

  // make this a global thing?
  uint32_t startingIndex = 0;

  // ACTORS
  Actor *actors = malloc(sizeof(Actor) * PARK_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, stump.dpl, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f }, FB_COUNT);
  actors[1] = setupActor(startingIndex + 1, stump.dpl, (float[3]){ 80.56f, 0.06f, -160.84f }, (float[3]){ 0.00f, -60.43f, 0.00f }, (float[3]){ 1.15f, 1.15f, 1.15f }, FB_COUNT);
  actors[2] = setupActor(startingIndex + 2, stump2.dpl, (float[3]){ -130.06f, -30.06f, -90.77f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f }, FB_COUNT);
  actors[3] = setupActor(startingIndex + 3, hedge.dpl, (float[3]){ 280.32f, 20.07f, -80.14f }, (float[3]){ 0.00f, -69.88f, 0.00f }, (float[3]){ 1.20f, 1.20f, 1.20f }, FB_COUNT);
  actors[4] = setupActor(startingIndex + 4, ground.dpl, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f }, FB_COUNT);
  actors[5] = setupActor(startingIndex + 5, hedge.dpl, (float[3]){ 280.32f, 20.07f, -80.14f }, (float[3]){ 0.00f, -69.88f, 0.00f }, (float[3]){ 1.20f, 1.20f, 1.20f }, FB_COUNT);
  actors[6] = setupActor(startingIndex + 6, hedge.dpl, (float[3]){ 280.32f, 20.07f, -80.14f }, (float[3]){ 0.00f, -69.88f, 0.00f }, (float[3]){ 1.20f, 1.20f, 1.20f }, FB_COUNT);
  actors[7] = setupActor(startingIndex + 7, stump2.dpl, (float[3]){ -130.06f, -30.06f, -90.77f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f }, FB_COUNT);
  // actors[8] = setupActor(startingIndex + 8, stump.dpl, (float[3]){ 8.56f, 0.06f, -16.84f }, (float[3]){ 0.00f, -60.43f, 0.00f }, (float[3]){ 1.15f, 1.15f, 1.15f }, FB_COUNT);

  Park.actors = actors;

  Park.id = 1;
  Park.actors = actors;
  
  T3DModel **models = malloc(sizeof(T3DModel *) * 4);
  models[0] = ground.model;
  models[1] = stump.model;
  models[2] = stump2.model;
  models[3] = hedge.model;

  Park.models = models;

  return Park;  
}

void unloadPark(void) {
  for (int i = 0; i < Park.modelCount; i++) {
    cleanupModel(Park.models[i]);
  }

  free(Park.models);

  for (int i = 0; i < Park.actorCount; i++) {
      deleteActor(&Park.actors[i]);
  }

  free(Park.actors);
}


// //   setupActor(startingIndex + 0, hedge, (float[3]){ -16.55f, 0.00f, 13.48f }, (float[3]){ 0.00f, 25.01f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 1, stump, (float[3]){ 3.58f, 0.00f, -4.42f }, (float[3]){ 0.00f, -60.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 2, stump2, (float[3]){ 5.82f, 0.00f, 9.98f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.50f, 1.00f });
// //   setupActor(startingIndex + 3, player, (float[3]){ -7.74f, 0.00f, 0.00f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 4, test_plane, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 12.00f, 12.00f, 12.00f });
// //   setupActor(startingIndex + 5, hedge copy, (float[3]){ -16.55f, 0.00f, 13.48f }, (float[3]){ 0.00f, 25.01f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 6, hedge copy copy, (float[3]){ -16.55f, 0.00f, 13.48f }, (float[3]){ 0.00f, 25.01f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 7, hedge copy copy copy, (float[3]){ -16.55f, 0.00f, 13.48f }, (float[3]){ 0.00f, 25.01f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 8, hedge copy copy copy copy, (float[3]){ -16.55f, 0.00f, 13.48f }, (float[3]){ 0.00f, 25.01f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f });
// //   setupActor(startingIndex + 9, stump2 copy, (float[3]){ 5.82f, 0.00f, 9.98f }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f, 1.50f, 1.00f });
// //   setupActor(startingIndex + 10, stump copy, (float[3]){ 3.58f, 0.00f, -4.42f }, (float[3]){ 0.00f, -60.00f, 0.00f }, (float[3]){ 1.00f, 1.00f, 1.00f })
// // }
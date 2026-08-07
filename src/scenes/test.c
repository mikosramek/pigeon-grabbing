/*
* TEST SCENE (.c)
* GENERATED ON 05/08/2026
*/
// INCLUDES
#include "test.h"


#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define TEST_ACTOR_COUNT 19

static Scene Test = (Scene) {
  .name = "Test",
  .actorCount = TEST_ACTOR_COUNT,
  .modelCount = 9,
};

// LOAD FUNCTION
Scene *createTest(uint32_t scene_id) {
  Test.id = scene_id;
  // MODEL IMPORT
  ModelData test_plane = setupModel("rom:/test_plane.t3dm");
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData rock_wall = setupModel("rom:/rock_wall.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData stump2 = setupModel("rom:/stump2.t3dm");
	ModelData hedge = setupModel("rom:/hedge.t3dm");
	ModelData gate = setupModel("rom:/gate.t3dm");
	ModelData hand = setupModel("rom:/hand.t3dm");

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 9);
  models[0] = test_plane.model;
	models[1] = two_cube.model;
	models[2] = rock_wall.model;
	models[3] = rock_post.model;
	models[4] = stump.model;
	models[5] = stump2.model;
	models[6] = hedge.model;
	models[7] = gate.model;
	models[8] = hand.model;

  Test.models = models;

  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * TEST_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, test_plane.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, two_cube.dpl, (float[3]){ 30.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, two_cube.dpl, (float[3]){ 20.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -20.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, two_cube.dpl, (float[3]){ 10.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, two_cube.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, two_cube.dpl, (float[3]){ 0.00f * xPositionMultiplier, 2.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, two_cube.dpl, (float[3]){ 30.00f * xPositionMultiplier, 2.00f * yPositionMultiplier, -30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, two_cube.dpl, (float[3]){ 10.00f * xPositionMultiplier, 2.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, two_cube.dpl, (float[3]){ 20.00f * xPositionMultiplier, 2.00f * yPositionMultiplier, -20.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[9] = setupActor(startingIndex + 9, rock_wall.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[10] = setupActor(startingIndex + 10, two_cube.dpl, (float[3]){ 10.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -11.99f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[11] = setupActor(startingIndex + 11, two_cube.dpl, (float[3]){ 12.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[12] = setupActor(startingIndex + 12, rock_post.dpl, (float[3]){ 3.75f * xPositionMultiplier, 0.00f * yPositionMultiplier, 30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[13] = setupActor(startingIndex + 13, rock_post.dpl, (float[3]){ -3.75f * xPositionMultiplier, 0.00f * yPositionMultiplier, 30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[14] = setupActor(startingIndex + 14, stump.dpl, (float[3]){ -15.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[15] = setupActor(startingIndex + 15, stump2.dpl, (float[3]){ -15.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[16] = setupActor(startingIndex + 16, hedge.dpl, (float[3]){ -15.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[17] = setupActor(startingIndex + 17, gate.dpl, (float[3]){ -11.12f * xPositionMultiplier, 0.00f * yPositionMultiplier, 30.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[18] = setupActor(startingIndex + 18, hand.dpl, (float[3]){ 7.62f * xPositionMultiplier, 2.91f * yPositionMultiplier, 20.09f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);

  Test.actors = actors;
  
  return &Test;  
}

// UNLOAD FUNCTION
void unloadTest(void) {
  for (int i = 0; i < Test.modelCount; i++) {
    cleanupModel(Test.models[i]);
  }

  free_uncached(Test.models);

  for (int i = 0; i < Test.actorCount; i++) {
    deleteActor(&Test.actors[i]);
  }

  free_uncached(Test.actors);
}

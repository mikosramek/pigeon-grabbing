/*
* TEST SCENE (.c)
* GENERATED ON 05/08/2026
*/
// INCLUDES
#include "test.h"


#include "../utils/pigeon_utils.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define TEST_ACTOR_COUNT 5

static Scene Test = (Scene) {
  .name = "Test",
  .actorCount = TEST_ACTOR_COUNT,
  .modelCount = 2,
};

// LOAD FUNCTION
Scene createTest(uint32_t FB_COUNT, uint32_t scene_id) {
  Test.id = scene_id;
  // MODEL IMPORT
  ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData test_plane = setupModel("rom:/test_plane.t3dm");

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 2);
  models[0] = two_cube.model;
	models[1] = test_plane.model;

  Test.models = models;

  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * TEST_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, two_cube.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, two_cube.dpl, (float[3]){ 2.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, two_cube.dpl, (float[3]){ 2.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 2.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, two_cube.dpl, (float[3]){ 2.00f * xPositionMultiplier, 2.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, test_plane.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);

  Test.actors = actors;
  
  return Test;  
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

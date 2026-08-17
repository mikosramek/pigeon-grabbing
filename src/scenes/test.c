/*
* TEST SCENE
* GENERATED ON 2026-08-15
*/
// INCLUDES
#include "test.h"

#include "scene.h"
#include "../globals.h"
#include "../utils/pigeon_utils.h"
#include "../entities/entity.h"

// ENTITIES


#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS

static Scene Test = (Scene) {
  .name = "Test",
  .actorCount = 9,
  .modelCount = 2,
  .entityCount = 0,
};

// LOAD FUNCTION
Scene *createTest(uint32_t scene_id) {
  Test.id = scene_id;
  // MODEL IMPORT
	ModelData two_cube = setupModel("rom:/two_cube.t3dm");
	ModelData test_plane = setupModel("rom:/test_plane.t3dm");


  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * Test.modelCount);
	models[0] = two_cube.model;
	models[1] = test_plane.model;


  Test.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * Test.actorCount);
	actors[0] = setupActor(startingIndex + 0, &test_plane, (float[3]){ 0.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.0f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, &two_cube, (float[3]){ 10.409882545471191f * xPositionMultiplier, 0.0f * yPositionMultiplier, -0.2506256401538849f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, &two_cube, (float[3]){ 10.409882545471191f * xPositionMultiplier, 2.0f * yPositionMultiplier, -0.2506256401538849f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, &two_cube, (float[3]){ 10.409882545471191f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.2506256699562073f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, &two_cube, (float[3]){ 10.409882545471191f * xPositionMultiplier, 4.0f * yPositionMultiplier, 1.7493743896484375f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, &two_cube, (float[3]){ 8.409882545471191f * xPositionMultiplier, 4.0f * yPositionMultiplier, -0.2506256401538849f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, &two_cube, (float[3]){ -3.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -7.0f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, &two_cube, (float[3]){ 3.0f * xPositionMultiplier, 0.0f * yPositionMultiplier, -7.0f * zPositionMultiplier }, (float[4]){ 1.0f, 0.0f, 0.0f, 0.0f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, &two_cube, (float[3]){ 0.4834599196910858f * xPositionMultiplier, 1.0249347686767578f * yPositionMultiplier, -7.0f * zPositionMultiplier }, (float[4]){ 0.8535534739494324f, 0.1464466005563736f, -0.3535533845424652f, 0.35355332493782043f }, (float[3]){ 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier, 1.000000f * scaleMultiplier}, false, false, FB_COUNT);

	// Entity Actors

  Test.actors = actors;

  struct Entity *entities = malloc_uncached(sizeof(struct Entity) * Test.entityCount);

  Test.entities = entities;
  
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
  free_uncached(Test.entities);
}

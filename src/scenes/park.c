/*
* PARK SCENE
* GENERATED ON 03/08/2026
*/
// INCLUDES
#include "park.h"


#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define PARK_ACTOR_COUNT 8

static Scene Park = (Scene) {
  .name = "Park",
  .actorCount = PARK_ACTOR_COUNT,
  .modelCount = 3,
};

// LOAD FUNCTION
Scene *createPark(uint32_t scene_id) {
  Park.id = scene_id;
  // MODEL IMPORT
  ModelData test_plane = setupModel("rom:/test_plane.t3dm");;
	ModelData stump = setupModel("rom:/stump.t3dm");;
	ModelData stump2 = setupModel("rom:/stump2.t3dm");;

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 3);
  models[0] = test_plane.model;
	models[1] = stump.model;
	models[2] = stump2.model;

  Park.models = models;

  // make this a global thing?
  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * PARK_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, test_plane.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, stump.dpl, (float[3]){ 10.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, -56.93f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, stump.dpl, (float[3]){ -10.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 36.13f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, stump.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, stump.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 41.80f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, stump2.dpl, (float[3]){ -7.50f * xPositionMultiplier, 0.00f * yPositionMultiplier, -7.50f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, stump2.dpl, (float[3]){ -5.16f * xPositionMultiplier, -2.00f * yPositionMultiplier, -7.50f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, stump.dpl, (float[3]){ 4.48f * xPositionMultiplier, 0.00f * yPositionMultiplier, -10.00f * zPositionMultiplier }, (float[3]){ 0.00f, 77.82f, 0.00f }, (float[3]){ 0.75f * scaleMultiplier, 0.75f * scaleMultiplier, 0.75f * scaleMultiplier}, FB_COUNT);

  Park.actors = actors;
  
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
}

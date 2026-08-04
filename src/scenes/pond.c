/*
* POND SCENE (.c)
* GENERATED ON 03/08/2026
*/
// INCLUDES
#include "pond.h"


#include "../utils/pigeon_utils.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define POND_ACTOR_COUNT 8

static Scene Pond = (Scene) {
  .name = "Pond",
  .actorCount = POND_ACTOR_COUNT,
  .modelCount = 5,
};

// LOAD FUNCTION
Scene createPond(uint32_t FB_COUNT, uint32_t scene_id) {
  Pond.id = scene_id;
  // MODEL IMPORT
  ModelData hedge = setupModel("rom:/hedge.t3dm");
	ModelData ground = setupModel("rom:/ground.t3dm");
	ModelData water = setupModel("rom:/water.t3dm");
	ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData stump2 = setupModel("rom:/stump2.t3dm");

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 5);
  models[0] = hedge.model;
	models[1] = ground.model;
	models[2] = water.model;
	models[3] = stump.model;
	models[4] = stump2.model;

  Pond.models = models;

  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.0f;
  float yPositionMultiplier = 6.0f;
  float zPositionMultiplier = 6.0f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * POND_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, hedge.dpl, (float[3]){ 15.92f * xPositionMultiplier, 1.29f * yPositionMultiplier, -16.22f * zPositionMultiplier }, (float[3]){ 0.00f, -39.87f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, ground.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, water.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.89f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, hedge.dpl, (float[3]){ 15.92f * xPositionMultiplier, 1.06f * yPositionMultiplier, -10.52f * zPositionMultiplier }, (float[3]){ 0.00f, 23.00f, 0.00f }, (float[3]){ 0.75f * scaleMultiplier, 0.75f * scaleMultiplier, 0.75f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, hedge.dpl, (float[3]){ 11.50f * xPositionMultiplier, -2.50f * yPositionMultiplier, -16.12f * zPositionMultiplier }, (float[3]){ 0.00f, -23.00f, 0.00f }, (float[3]){ 0.75f * scaleMultiplier, 0.75f * scaleMultiplier, 0.75f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, stump.dpl, (float[3]){ -14.36f * xPositionMultiplier, 0.00f * yPositionMultiplier, 16.38f * zPositionMultiplier }, (float[3]){ 0.00f, 14.57f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, stump2.dpl, (float[3]){ 15.34f * xPositionMultiplier, -0.77f * yPositionMultiplier, 17.09f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, stump2.dpl, (float[3]){ 17.20f * xPositionMultiplier, -1.30f * yPositionMultiplier, 13.28f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 0.80f * scaleMultiplier, 0.80f * scaleMultiplier, 0.80f * scaleMultiplier}, FB_COUNT);

  Pond.actors = actors;
  
  return Pond;  
}

// UNLOAD FUNCTION
void unloadPond(void) {
  for (int i = 0; i < Pond.modelCount; i++) {
    cleanupModel(Pond.models[i]);
  }

  free_uncached(Pond.models);

  for (int i = 0; i < Pond.actorCount; i++) {
    deleteActor(&Pond.actors[i]);
  }

  free_uncached(Pond.actors);
}

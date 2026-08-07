/*
* HEDGES SCENE (.c)
* GENERATED ON 03/08/2026
*/
// INCLUDES
#include "hedges.h"


#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define HEDGES_ACTOR_COUNT 6

static Scene Hedges = (Scene) {
  .name = "Hedges",
  .actorCount = HEDGES_ACTOR_COUNT,
  .modelCount = 2,
};

// LOAD FUNCTION
Scene *createHedges(uint32_t scene_id) {
  Hedges.id = scene_id;
  // MODEL IMPORT
  ModelData test_plane = setupModel("rom:/test_plane.t3dm");
	ModelData hedge = setupModel("rom:/hedge.t3dm");

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 2);
  models[0] = test_plane.model;
	models[1] = hedge.model;

  Hedges.models = models;

  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * HEDGES_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, test_plane.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, hedge.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, -6.80f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, hedge.dpl, (float[3]){ -3.11f * xPositionMultiplier, 0.00f * yPositionMultiplier, -6.80f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, hedge.dpl, (float[3]){ -6.40f * xPositionMultiplier, 0.00f * yPositionMultiplier, -6.80f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, hedge.dpl, (float[3]){ 3.35f * xPositionMultiplier, 0.00f * yPositionMultiplier, -6.80f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, hedge.dpl, (float[3]){ 6.65f * xPositionMultiplier, 0.00f * yPositionMultiplier, -6.80f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);

  Hedges.actors = actors;
  
  return &Hedges;  
}

// UNLOAD FUNCTION
void unloadHedges(void) {
  for (int i = 0; i < Hedges.modelCount; i++) {
    cleanupModel(Hedges.models[i]);
  }

  free_uncached(Hedges.models);

  for (int i = 0; i < Hedges.actorCount; i++) {
      deleteActor(&Hedges.actors[i]);
  }

  free_uncached(Hedges.actors);
}

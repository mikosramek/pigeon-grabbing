/*
* POND SCENE (.c)
* GENERATED ON 05/08/2026
*/
// INCLUDES
#include "pond.h"


#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

// DEFINITIONS
#define POND_ACTOR_COUNT 13

static Scene Pond = (Scene) {
  .name = "Pond",
  .actorCount = POND_ACTOR_COUNT,
  .modelCount = 9,
	.entityCount = 0,
};

// LOAD FUNCTION
Scene *createPond(uint32_t scene_id) {
  Pond.id = scene_id;
  // MODEL IMPORT
  ModelData stump = setupModel("rom:/stump.t3dm");
	ModelData park_ground_sw = setupModel("rom:/park_ground_sw.t3dm");
	ModelData gate = setupModel("rom:/gate.t3dm");
	ModelData water = setupModel("rom:/water.t3dm");
	ModelData park_ground_ne = setupModel("rom:/park_ground_ne.t3dm");
	ModelData park_ground_nw = setupModel("rom:/park_ground_nw.t3dm");
	ModelData park_ground_se = setupModel("rom:/park_ground_se.t3dm");
	ModelData rock_post = setupModel("rom:/rock_post.t3dm");
	ModelData rock_wall = setupModel("rom:/rock_wall.t3dm");

  T3DModel **models = malloc_uncached(sizeof(T3DModel *) * 9);
  models[0] = stump.model;
	models[1] = park_ground_sw.model;
	models[2] = gate.model;
	models[3] = water.model;
	models[4] = park_ground_ne.model;
	models[5] = park_ground_nw.model;
	models[6] = park_ground_se.model;
	models[7] = rock_post.model;
	models[8] = rock_wall.model;

  Pond.models = models;

  uint32_t startingIndex = 0;
  float xPositionMultiplier = 6.4f;
  float yPositionMultiplier = 6.4f;
  float zPositionMultiplier = 6.4f;
  float scaleMultiplier = 0.1f;

  // ACTORS
  Actor *actors = malloc_uncached(sizeof(Actor) * POND_ACTOR_COUNT);
  actors[0] = setupActor(startingIndex + 0, stump.dpl, (float[3]){ -15.29f * xPositionMultiplier, 0.00f * yPositionMultiplier, 15.99f * zPositionMultiplier }, (float[3]){ 0.00f, -80.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[1] = setupActor(startingIndex + 1, park_ground_sw.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[2] = setupActor(startingIndex + 2, gate.dpl, (float[3]){ -39.82f * xPositionMultiplier, -0.61f * yPositionMultiplier, 60.24f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[3] = setupActor(startingIndex + 3, water.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[4] = setupActor(startingIndex + 4, park_ground_ne.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[5] = setupActor(startingIndex + 5, park_ground_nw.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[6] = setupActor(startingIndex + 6, park_ground_se.dpl, (float[3]){ 0.00f * xPositionMultiplier, 0.00f * yPositionMultiplier, 0.00f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[7] = setupActor(startingIndex + 7, rock_post.dpl, (float[3]){ -47.45f * xPositionMultiplier, 0.00f * yPositionMultiplier, 60.13f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[8] = setupActor(startingIndex + 8, rock_post.dpl, (float[3]){ -32.18f * xPositionMultiplier, 0.00f * yPositionMultiplier, 60.13f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[9] = setupActor(startingIndex + 9, rock_wall.dpl, (float[3]){ -28.44f * xPositionMultiplier, -0.46f * yPositionMultiplier, 60.26f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[10] = setupActor(startingIndex + 10, rock_wall.dpl, (float[3]){ -51.14f * xPositionMultiplier, -0.46f * yPositionMultiplier, 60.26f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[11] = setupActor(startingIndex + 11, rock_post.dpl, (float[3]){ -24.59f * xPositionMultiplier, 0.00f * yPositionMultiplier, 60.13f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);
	actors[12] = setupActor(startingIndex + 12, rock_post.dpl, (float[3]){ -55.10f * xPositionMultiplier, 0.00f * yPositionMultiplier, 60.13f * zPositionMultiplier }, (float[3]){ 0.00f, 0.00f, 0.00f }, (float[3]){ 1.00f * scaleMultiplier, 1.00f * scaleMultiplier, 1.00f * scaleMultiplier}, FB_COUNT);

  Pond.actors = actors;
  
  return &Pond;  
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

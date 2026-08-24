
#include "park_level.h"
#include <libdragon.h>
#include "../level.h"
#include "../scenes/scene.h"
#include "../scenes/park.h"
#include "../scenes/test.h"

static struct Level ParkLevel = {
  .id = 1,
  .startingSceneID = 0,
  .startingSpawnID = 0, // will I ever need to change this???
};


void registerParkLevel() {
  ParkLevel.scenes[0] = getBasePark();
  ParkLevel.scenes[1] = getBaseTest();
  ParkLevel.loadScene = changeParkScene;
}

struct Level *loadParkLevel() {
  // use ID to find which scene to start with
  // Scene *startingScene = NULL;
  // for (int i = 0; i < len(ParkLevel.scenes); i += 1) {
  //   if (ParkLevel.scenes[i]->id == ParkLevel.startingSceneID) {
  //     startingScene = ParkLevel.scenes[i];
  //   }
  // }
  // assertf(startingScene != NULL, "Starting scene with id of %d doesn't exist!", ParkLevel.startingSceneID);

  
  // createPark loads in the park
  ParkLevel.activeScene = createPark();

  return &ParkLevel;
}

void changeParkScene(uint32_t sceneID) {
  // Scene *nextScene = NULL;
  // for (int i = 0; i < len(ParkLevel.scenes); i += 1) {
  //   if (ParkLevel.scenes[i]->id == sceneID) {
  //     nextScene = ParkLevel.scenes[i];
  //   }
  // }
  // assertf(nextScene != NULL, "Next scene with id of %d doesn't exist!", sceneID);
  switch (ParkLevel.activeScene->id) {
    case 0: unloadPark(); break;
    case 1: unloadTest(); break;
    default: assertf(false, "Current scene doesn't have an unload: %d", (int)ParkLevel.activeScene->id);
  }

  switch (sceneID) {
    case 0: ParkLevel.activeScene = createPark(); break;
    case 1: ParkLevel.activeScene = createTest(); break;
    default: assertf(false, "Trying to load a scene that doesn't exist: %d", (int)sceneID);
  }
}


void unloadParkLevel() {
  // free_uncached(ParkLevel.scenes);
}

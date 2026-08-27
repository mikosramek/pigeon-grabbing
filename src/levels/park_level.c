
#include "park_level.h"
#include <libdragon.h>
#include "../level.h"
#include "../scenes/scene.h"
#include "../scenes/test.h"
#include "../scenes/park.h"
#include "../scenes/parkNorth.h"
#include "../player/player.h"

static struct Level ParkLevel = {
  .id = 1,
  .totalFeatherCount = 3,
};


void registerParkLevel() {
  ParkLevel.scenes[0] = getBasePark();
  ParkLevel.scenes[1] = getBaseParkNorth();
  ParkLevel.scenes[2] = getBaseTest();
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
  // ParkLevel.activeScene = createParkNorth();
  changeParkScene(-1, -1);

  return &ParkLevel;
}

void changeParkScene(uint32_t sceneID, uint32_t spawnPointID) {
  // Scene *nextScene = NULL;
  // for (int i = 0; i < len(ParkLevel.scenes); i += 1) {
  //   if (ParkLevel.scenes[i]->id == sceneID) {
  //     nextScene = ParkLevel.scenes[i];
  //   }
  // }
  // assertf(nextScene != NULL, "Next scene with id of %d doesn't exist!", sceneID);
  // if (ParkLevel.activeScene != NULL) {
  //   switch (ParkLevel.activeScene->id) {
  //     case -1: unloadTest(); break;
  //     case 0: unloadPark(); break;
  //     case 1: unloadParkNorth(); break;
  //     default: assertf(false, "Current scene doesn't have an unload: %d", (int)ParkLevel.activeScene->id);
  //   }
  // }

  switch (sceneID) {
    case -1: ParkLevel.activeScene = createTest(); break;
    case 0: ParkLevel.activeScene = createPark(); break;
    case 1: ParkLevel.activeScene = createParkNorth(); break;
    default: assertf(false, "Trying to load a scene that doesn't exist: %d", (int)sceneID);
  }

  SpawnPoint *spawn = NULL;
  for (int i = 0; i < ParkLevel.activeScene->spawnCount; i += 1) {
    uint32_t id = ParkLevel.activeScene->spawns[i].id;
    if (id == spawnPointID) {
      spawn = &ParkLevel.activeScene->spawns[i];
    }
  }

  assertf(spawn != NULL, "NO SPAWN FOUND!");
  
  // move player to spawnPoint
  Player *p = getPlayer();
  p->position = spawn->spawn;
  p->cameraAngle = spawn->angle;

}


void unloadParkLevel() {
  // free_uncached(ParkLevel.scenes);
  unloadPark();
  unloadParkNorth();
  unloadTest();
}

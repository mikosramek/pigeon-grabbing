
#include "park_level.h"
#include <libdragon.h>
#include "../level.h"
#include "../scenes/scene.h"
#include "../scenes/test.h"
#include "../scenes/park.h"
#include "../scenes/parkNorth.h"
#include "../scenes/parkBeach.h"
#include "../player/player.h"

static struct Level ParkLevel = {
  .id = 1,
  .totalFeatherCount = 3,
};


void registerParkLevel() {
  ParkLevel.scenes[0] = getBasePark();
  ParkLevel.scenes[1] = getBaseParkNorth();
  ParkLevel.scenes[2] = getBaseParkBeach();
  ParkLevel.scenes[3] = getBaseTest();
  ParkLevel.loadScene = changeParkScene;
}

struct Level *loadParkLevel() {
  changeParkScene(-1, -1);
  return &ParkLevel;
}

void changeParkScene(uint32_t sceneID, uint32_t spawnPointID) {
  if (ParkLevel.activeScene != NULL) {
    switch (ParkLevel.activeScene->id) {
      case -1: rdpq_call_deferred(unloadTest, NULL); break;
      case 0: rdpq_call_deferred(unloadPark, NULL); break;
      case 1: rdpq_call_deferred(unloadParkNorth, NULL); break;
      case 2: rdpq_call_deferred(unloadParkBeach, NULL); break;
      default: assertf(false, "Current scene doesn't have an unload: %d", (int)ParkLevel.activeScene->id);
    }
  }

  switch (sceneID) {
    case -1: ParkLevel.activeScene = createTest(); break;
    case 0: ParkLevel.activeScene = createPark(); break;
    case 1: ParkLevel.activeScene = createParkNorth(); break;
    case 2: ParkLevel.activeScene = createParkBeach(); break;
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
  rdpq_call_deferred(unloadTest, NULL);
  rdpq_call_deferred(unloadPark, NULL);
  rdpq_call_deferred(unloadParkNorth, NULL);
  rdpq_call_deferred(unloadParkBeach, NULL);
}

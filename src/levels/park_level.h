#ifndef PARK_LEVEL_H
#define PARK_LEVEL_H

#include <libdragon.h>
#include "../level.h"
#include "../scenes/test.h"
#include "../scenes/scene.h"
#include "../scenes/park.h"
#include "../scenes/parkNorth.h"
#include "../player/player.h"

void registerParkLevel(void);
struct Level *loadParkLevel(void);
void unloadParkLevel(void);

void changeParkScene(uint32_t sceneID, uint32_t spawnPointID);

#endif

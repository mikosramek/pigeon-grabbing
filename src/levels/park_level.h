#ifndef PARK_LEVEL_H
#define PARK_LEVEL_H

#include <libdragon.h>
#include "../level.h"
#include "../scenes/scene.h"

void registerParkLevel(void);
struct Level *loadParkLevel(void);
void unloadParkLevel(void);

void changeParkScene(uint32_t sceneID);

#endif

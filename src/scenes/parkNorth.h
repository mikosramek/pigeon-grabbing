#ifndef PARK_NORTH_H
#define PARK_NORTH_H

#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"
#include "../entities/entity.h"
#include "../entities/feather.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

Scene *getBaseParkNorth(void);

Scene *createParkNorth(void);

void unloadParkNorth(void *arg);

#endif

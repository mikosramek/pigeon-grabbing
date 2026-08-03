#ifndef PARK_H
#define PARK_H

#include "../utils/pigeon_utils.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

Scene createPark(uint32_t FB_COUNT);

void unloadPark(void);

#endif

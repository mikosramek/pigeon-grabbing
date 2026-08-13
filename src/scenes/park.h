#ifndef PARK_H
#define PARK_H

#include "../utils/pigeon_utils.h"
#include "../globals.h"
#include "scene.h"
#include "../entities/entity.h"
#include "../entities/feather.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

Scene *createPark(uint32_t scene_id);

void unloadPark(void);

#endif

/*
* POND SCENE (.h)
* GENERATED ON 03/08/2026
*/
#ifndef POND_H
#define POND_H

#include "../utils/pigeon_utils.h"
#include "scene.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <t3d/t3dmodel.h>

Scene createPond(uint32_t FB_COUNT, uint32_t scene_id);

void unloadPond(void);

#endif

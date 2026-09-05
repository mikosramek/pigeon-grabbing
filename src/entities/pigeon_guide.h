#ifndef PIGEON_GUIDE_H
#define PIGEON_GUIDE_H

#include "entity.h"
#include "../state.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_ui.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

void pigeon_guide_update(struct Entity *pigeon, uint32_t time);
bool pigeon_guide_can_interact(struct Entity *pigeon);
void pigeon_guide_interact(struct Entity *pigeon);
void pigeon_guide_interaction_ui(void);

struct Entity pigeon_guide_create(uint32_t entityId, Actor *actor);

#endif
#ifndef FEATHER_H
#define FEATHER_H

#include "entity.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_ui.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

void updateFeather(struct Entity *feather, uint32_t time);
bool canInteract(struct Entity *feather);
void interact(struct Entity *feather);
void interactionUI(void);

struct Entity feather_create(uint32_t entityId, Actor *actor);

#endif
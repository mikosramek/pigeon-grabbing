#ifndef FEATHER_H
#define FEATHER_H

#include "entity.h"
#include "../globals.h"
#include "../player/player.h"
#include "../utils/pigeon_utils.h"

#include "math.h"

void updateFeather(struct Entity *feather, uint32_t time);
bool canInteract(struct Entity *feather);
void interact(struct Entity *feather);
// bool canInteract(struct Entity *feather, Player *player);
void interactionUI(void);

float getPlayerDist(struct Entity *feather);

struct Entity createFeather(Actor *actor);

#endif
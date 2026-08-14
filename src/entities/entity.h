#ifndef ENTITY_H
#define ENTITY_H

#include "../utils/pigeon_utils.h"

struct Entity {
  Actor *actor;
  bool skip; // ie the item has been collected. each entity should determine what skip means for it
  void (*update)(struct Entity *entity, uint32_t time);
  bool (*canInteract)(struct Entity *entity);
  void (*interact)(struct Entity *entity);
  void (*interactionUI)(void);
};

#endif
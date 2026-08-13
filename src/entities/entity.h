#ifndef ENTITY_H
#define ENTITY_H

#include "../utils/pigeon_utils.h"

struct Entity {
  Actor *actor;
  void (*update)(struct Entity *entity, uint32_t time);
};

#endif
#include "feather.h"

#include "entity.h"
#include "../globals.h"

#include "math.h"

void updateFeather(struct Entity *feather, uint32_t time) {
  float yOffset = sin(time / 10.0f) * 0.75f;
  feather->actor->pos[1] = feather->actor->staticPos[1] + yOffset;
}

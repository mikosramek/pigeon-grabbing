#include "doors.h"
#include <libdragon.h>
#include "../state.h"
#include "../player/player.h"

void handle_doors(void) {
  State *state = getState();
  fm_vec3_t pos = getPlayer()->position;

  Door *doors = state->activeLevel->activeScene->doors;
  for (int i = 0; i < state->activeLevel->activeScene->doorCount; i += 1) {
    bool xAligned = pos.x >= doors[i].aabbMin.x && pos.x <= doors[i].aabbMax.x;
    bool zAligned = pos.z >= doors[i].aabbMin.z && pos.z <= doors[i].aabbMax.z;
    if(xAligned && zAligned) {
      state->activeLevel->loadScene(1, 0);
    }
  }
};

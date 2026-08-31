#include "libdragon.h"
#include "state.h"

void state_update_feather(uint32_t id, enum EntityState newState) {
  State *state = getState();
  state->feathers[id] = newState;
}

enum EntityState state_get_feather(uint32_t id) {
  State *state = getState();
  return state->feathers[id];
}
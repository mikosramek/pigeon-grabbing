#ifndef STATE_H
#define STATE_H

#include "level.h"
#include "scenes/scene.h"   // Because State contains a Scene *

// ENTITY STATE DICT LIST
enum EntityState {
  ACTIVE,
  INACTIVE,
};

struct entityState_entry {
  uint32_t id;
  enum EntityState state;
  struct entityState_entry *nextEntry;
};

struct entityState_entry* entity_state_init(bool states[]);
struct entityState_entry* entity_state_find(uint32_t id);
void entity_state_update(uint32_t id, enum EntityState state);

// STATE
typedef struct {
  struct Level *activeLevel;
  int requestSceneId;
  int feathersCollected;
  struct entityState_entry *entityState;
} State;

State *getState(void);

// DEBUG
enum DebugInfoMode {
  CAMERA,
  AUDIO,
  SCENE,
  HIDDEN
}; 

typedef struct {
  bool debugEnabled;
  enum DebugInfoMode infoMode;
} Debug;

#endif
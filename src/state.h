#ifndef STATE_H
#define STATE_H

#include "level.h"
#include "scenes/scene.h"   // Because State contains a Scene *

// ENTITY STATE DICT LIST
enum EntityState {
  ACTIVE,
  INACTIVE,
};

// STATE
typedef struct {
  struct Level *activeLevel;
  int requestSceneId;
  int feathersCollected;
  struct entityState_entry *entityState;
  enum EntityState feathers[3];
  float debugPos[3];
} State;

State *getState(void);

// FEATHERS
void state_update_feather(uint32_t id, enum EntityState newState);
enum EntityState state_get_feather(uint32_t id);

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
#ifndef STATE_H
#define STATE_H

#include "scenes/scene.h"   // Because State contains a Scene *

typedef struct {
    Scene *activeScene;
    int requestSceneId;
} State;

State *getState(void);

#endif
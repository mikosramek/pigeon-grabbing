#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <libdragon.h>
#include "state.h"
#include "scenes/park.h"
#include "scenes/test.h"

typedef struct SceneManager SceneManager;

struct SceneManager
{
  int sceneCount;
  void (*update)();
  void (*loadScene)(int sceneId);
};

SceneManager* scene_manager_create(int initial_scene_id);
void scene_manager_destroy(SceneManager* self);


#endif
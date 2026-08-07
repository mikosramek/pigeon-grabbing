#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <libdragon.h>
#include "state.h"
#include "scenes/park.h"
#include "scenes/hedges.h"
#include "scenes/pond.h"
#include "scenes/test.h"

typedef struct SceneManager SceneManager;

struct SceneManager
{
  int sceneCount;
  void (*update)();
  void (*loadScene)(int sceneId);
};

SceneManager* Scene_Manager_Create(int initial_scene_id);
void Scene_Manager_Destroy(SceneManager* self);


#endif
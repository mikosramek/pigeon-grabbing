#ifndef LEVEL_H
#define LEVEL_H

#include "libdragon.h"
#include "./scenes/scene.h"

struct Level {
  uint32_t id;
  uint32_t totalFeatherCount;
  Scene *activeScene;
  Scene *scenes[5];
  void (*loadScene)(uint32_t sceneID, uint32_t spawnPointID);
};


#endif
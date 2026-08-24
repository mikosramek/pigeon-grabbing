#ifndef LEVEL_H
#define LEVEL_H

#include "libdragon.h"
#include "./scenes/scene.h"

struct Level {
  uint32_t id;
  uint32_t startingSceneID;
  uint32_t startingSpawnID;
  Scene *activeScene;
  Scene *scenes[5];
  void (*loadScene)(uint32_t sceneID);
};

// struct Entity {
//   int entityId;
//   Actor *actor;
//   bool skip; // ie the item has been collected. each entity should determine what skip means for it
//   void (*update)(struct Entity *entity, uint32_t time);
//   bool (*canInteract)(struct Entity *entity);
//   void (*interact)(struct Entity *entity);
//   void (*interactionUI)(void);
//   int interactionMax[3];
//   int interactionMin[3];
// };


#endif
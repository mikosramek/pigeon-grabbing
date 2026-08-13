#ifndef PLAYER_H
#define PLAYER_H

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"
#include "../utils/pigeon_audio.h"
#include "inventory.h"

// typedef struct {
//   bool sunflower;
// } PlayerInventory;

enum InventorySlot {
  IS_EMPTY,
  IS_SUNFLOWER
};

typedef struct {
  float cameraY;
  float cameraTargetY;
  float cameraAngle;
  fm_vec3_t position;
  fm_vec3_t cameraTarget;
  float movementSpeed;
  float cameraRotationSpeed;
  bool inventory;
  enum InventorySlot activeSlot;
  sprite_t *inventoryFrame;
  sprite_t *inventoryArrow;
  sprite_t *ui_b;
  float movementTally;
  bool hasStepped;
  struct InventoryItem *currentItem;
} Player;

Player *getPlayer(void);

void initPlayer(bool inventory[]);

void resetPlayer(void);

void updatePlayer(void);

void drawPlayerUI(void);

#endif
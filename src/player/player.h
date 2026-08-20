#ifndef PLAYER_H
#define PLAYER_H

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"
#include "../utils/pigeon_audio.h"
#include "../entities/entity.h"
#include "../state.h"
#include "inventory.h"

// typedef struct {
//   bool sunflower;
// } PlayerInventory;

typedef struct {
  float cameraY;
  float cameraTargetY;
  float cameraAngle;
  float cameraFOV;
  fm_vec3_t position;
  fm_vec3_t cameraTarget;
  float movementSpeed;
  float cameraRotationSpeed;
  float verticalCameraSpeed;
  sprite_t *inventoryFrame;
  sprite_t *inventoryArrow;
  sprite_t *ui_b;
  float movementTally;
  bool hasStepped;
  struct InventoryItem *currentItem;
  struct Entity *closestEntity;
} Player;

Player *getPlayer(void);

void player_init(bool inventory[]);

void resetPlayer(void);

void player_update(void);
void player_handle_movement(void);
void player_handle_interaction(void);
void player_draw_ui(void);
void player_detect_closest_entity (void);

#endif
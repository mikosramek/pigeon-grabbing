#include "player.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"
#include "../utils/pigeon_audio.h"
#include "../entities/entity.h"
#include "../state.h"
#include "inventory.h"

const float DEFAULT_CAMERA_Y = 20.0f;
const float DEFAULT_CAMERA_FOV = 85.0f;
const int8_t stickThreshold = 20;

static Player player = {
  .cameraFOV = DEFAULT_CAMERA_FOV,
  .cameraY = DEFAULT_CAMERA_Y,
  .position = {{ 0, DEFAULT_CAMERA_Y, 0 }},
  .cameraTarget = {{ 0, DEFAULT_CAMERA_Y, 0 }},
  .cameraAngle = -M_PI / 2,
  .movementSpeed = 0.6f,
  .cameraRotationSpeed = 0.03f,
  .hasStepped = false,
  .closestEntity = NULL,
};

Player *getPlayer(void)
{
    return &player;
}

void initPlayer(bool inventory[]) {
  player.inventoryFrame = sprite_load("rom:/inventory_frame.sprite");
  player.inventoryArrow = sprite_load("rom:/ui_arrow.sprite");
  player.ui_b = sprite_load("rom:/ui_b.sprite");

  player.currentItem = init_inventory(inventory);
}

void resetPlayer() {
  Player *player = getPlayer();
  player->cameraY = DEFAULT_CAMERA_Y;
  player->cameraFOV = DEFAULT_CAMERA_FOV;
  player->position = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player->cameraTarget = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player->cameraAngle = -M_PI / 2;
  player->movementTally = 0;
  player->hasStepped = false;
}

void updatePlayer() {
  Player *player = getPlayer();
  
  joypad_inputs_t input = joypad_get_inputs(0);

  // MOVEMENT INPUTS
  float xInput = 0.0f;
  float yInput = 0.0f;  
  if (input.stick_x > stickThreshold) {
    player->cameraAngle += 1.0f * player->cameraRotationSpeed;
    // xInput = 1.00f;
  } else if (input.stick_x < -1 * stickThreshold) {
    player->cameraAngle -= 1.0f * player->cameraRotationSpeed;
    // xInput = -1.00f;
  }
  if (input.stick_y > stickThreshold) {
    yInput = 1.0f;
  }else if (input.stick_y < -1 * stickThreshold) {
    yInput = -1.0f;
  }

  // CAMERA INPUTS
  if (input.cstick_x > 0) {
    // cameraAngle += 1.0f * cameraRotationSpeed;
    xInput = 1.00f;
  } else if (input.cstick_x < 0) {
    // cameraAngle -= 1.0f * cameraRotationSpeed;
    xInput = -1.00f;
  }
  player->cameraAngle = fmod(player->cameraAngle, M_PI * 2.0f);

  if (input.cstick_y > 0) {
    player->cameraY -= 0.5f * player->cameraRotationSpeed;
  } else if (input.cstick_y < 0) {
    player->cameraY += 0.5f * player->cameraRotationSpeed;
  }
  player->cameraY = clamp(player->cameraY, 19.0f, 20.6f);

  fm_vec3_t inputVector = {{ xInput, yInput, 0.0f }};
  fm_vec3_norm(&inputVector, &inputVector);

  // get forward angle
  float xTarget = cos(player->cameraAngle);
  float zTarget = sin(player->cameraAngle);

  // get perpendicular angle
  float perpXTarget = cos(player->cameraAngle + M_PI / 2.0f);
  float perpZTarget = sin(player->cameraAngle + M_PI / 2.0f);

  // UPDATE CAMERA

  // combine forward/back input + forward angle AND left/right input + perp angle
  float zChange = (inputVector.y * zTarget) + (inputVector.x * perpZTarget);
  float xChange = (inputVector.y * xTarget) + (inputVector.x * perpXTarget);

  // normalize input, so angular movement isn't doubled
  fm_vec3_t posChange = {{ xChange, 0, zChange }};
  fm_vec3_norm(&posChange, &posChange);

  // get some sort of camera motion
  if (posChange.x != 0 || posChange.z != 0) {
    player->movementTally += 0.01f;
  }
  float stepHeight = 0.75f;
  float yOffset = stepHeight * sin(player->movementTally / 0.1f);
  
  // apply position
  player->position.z += posChange.z * player->movementSpeed;
  player->position.x += posChange.x * player->movementSpeed;
  player->position.y = DEFAULT_CAMERA_Y + yOffset;

  // apply camera target
  player->cameraTarget.x = player->position.x + xTarget;
  player->cameraTarget.y = player->cameraY + yOffset;
  player->cameraTarget.z = player->position.z + zTarget;


  if (yOffset <= stepHeight * -0.9f && !player->hasStepped) {
    // playSFX(STEP);
    player->hasStepped = true;
  } else if (yOffset >= stepHeight * -.9f && player->hasStepped) {
    player->hasStepped = false;
  }
}

void handlePlayerInput(void) {
  Player *player = getPlayer();
  joypad_buttons_t pressedButtons = joypad_get_buttons_pressed(0);

  if (player->closestEntity != NULL) {
    if (pressedButtons.a) {
      player->closestEntity->interact(player->closestEntity);
    }
  } else {
    // handle using item
  }

  if (pressedButtons.b) {
    player->currentItem = getNextUnlockedItem(player->currentItem);
  }
}

// RESOLUTION_320x240
void drawPlayerUI(void) {

  // active item
  if (player.currentItem->sprite) {
    rdpq_sprite_blit(player.currentItem->sprite, 320 - 32, 240 - 28, &(rdpq_blitparms_t){
      .scale_x = 0.5f, .scale_y = 0.5f,
    });
  }

  // base item frame
  rdpq_sprite_blit(player.inventoryFrame, 320 - 40, 240-36, NULL);

  if (player.closestEntity != NULL) {
    player.closestEntity->interactionUI();
  }

  // is there a good way to detect what's the next item?
}

void handleEntities (void) {
  State *state = getState();

  // float closestDistance = 1000;
  struct Entity *closestEntity = NULL;

  struct Entity *entities = state->activeScene->entities;
  for (int i = 0; i < state->activeScene->entityCount; i++) {
    // move distance logic here
    if (entities[i].canInteract(&entities[i])) {
      closestEntity = &entities[i];
    }
  }
  player.closestEntity = closestEntity;
}

// todo:
// - throw seed
// - pet pigeon
// - collect golden feathers
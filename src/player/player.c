#include "player.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"

const float DEFAULT_CAMERA_Y = 20.0f;
const int8_t stickThreshold = 20;

static Player player = {
  .cameraY = DEFAULT_CAMERA_Y,
  .position = {{ 0, DEFAULT_CAMERA_Y, 0 }},
  .cameraTarget = {{ 0, DEFAULT_CAMERA_Y, 0 }},
  .cameraAngle = -M_PI / 2,
  .movementSpeed = 2,
  .cameraRotationSpeed = 0.05f,
};

Player *getPlayer(void)
{
    return &player;
}

void resetPlayer() {
  Player *player = getPlayer();
  player->cameraY = 20.0f;
  player->cameraTarget = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player->position = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player->cameraAngle = -M_PI / 2;
}

void updatePlayer() {

  Player *player = getPlayer();
  
  joypad_poll();
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
  float zChange = (inputVector.y * zTarget * player->movementSpeed) + (inputVector.x * perpZTarget * player->movementSpeed);
  float xChange = (inputVector.y * xTarget * player->movementSpeed) + (inputVector.x * perpXTarget * player->movementSpeed);

  // normalize input, so angular movement isn't doubled
  fm_vec3_t posChange = {{ xChange, 0, zChange }};
  fm_vec3_norm(&posChange, &posChange);
  
  // apply position
  player->position.z += posChange.z;
  player->position.x += posChange.x;

  // apply camera target
  player->cameraTarget.x = player->position.x + xTarget;
  player->cameraTarget.y = player->cameraY;
  player->cameraTarget.z = player->position.z + zTarget;
}
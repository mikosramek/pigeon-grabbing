#include "player.h"

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"
#include "../utils/pigeon_audio.h"
#include "../entities/entity.h"
#include "../state.h"
#include "inventory.h"

const float DEFAULT_CAMERA_Y = 10.0f;
const float DEFAULT_CAMERA_FOV = 85.0f;
const float DEFAULT_PLAYER_SPEED = 0.8f;
const float stepHeight = 0.75f;
const int8_t stickThreshold = 20;

static Player player = {
  .cameraFOV = DEFAULT_CAMERA_FOV,
  .cameraY = DEFAULT_CAMERA_Y,
  .position = {{ 0.0f, DEFAULT_CAMERA_Y, 0.0f }},
  .cameraTarget = {{ 0.0f, DEFAULT_CAMERA_Y, 0.0f }},
  .cameraAngle = -M_PI * 0.5f,
  .movementSpeed = DEFAULT_PLAYER_SPEED,
  .cameraRotationSpeed = 0.03f,
  .verticalCameraSpeed = 0.1f,
  .hasStepped = false,
  .closestEntity = NULL,
};

Player *getPlayer(void)
{
    return &player;
}

void player_init(bool inventory[]) {
  player.inventoryFrame = sprite_load("rom:/inventory_frame.sprite");
  player.inventoryArrow = sprite_load("rom:/ui_arrow.sprite");
  player.ui_b = sprite_load("rom:/ui_b.sprite");

  player.currentItem = inventory_init(inventory);
}

void resetPlayer() {
  player.cameraY = DEFAULT_CAMERA_Y;
  player.cameraFOV = DEFAULT_CAMERA_FOV;
  player.position = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player.cameraTarget = (fm_vec3_t){{ 0, DEFAULT_CAMERA_Y, 0 }};
  player.cameraAngle = -M_PI * 0.5f;
  player.movementTally = 0;
  player.hasStepped = false;
}

void player_update() {
  player_handle_movement();
  player_handle_interaction();
}

void player_handle_movement(void) {  
  joypad_inputs_t input = joypad_get_inputs(0);

  // MOVEMENT INPUTS
  float xInput = 0.0f;
  float yInput = 0.0f;  
  if (input.stick_x > stickThreshold) {
    player.cameraAngle += 1.0f * player.cameraRotationSpeed;
    // xInput = 1.00f;
  } else if (input.stick_x < -1 * stickThreshold) {
    player.cameraAngle -= 1.0f * player.cameraRotationSpeed;
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
  player.cameraAngle = fmod(player.cameraAngle, M_PI * 2.0f);

  if (input.cstick_y > 0) {
    player.cameraY -= 0.5f * player.verticalCameraSpeed;
  } else if (input.cstick_y < 0) {
    player.cameraY += 0.5f * player.verticalCameraSpeed;
  }
  player.cameraY = clamp(player.cameraY, DEFAULT_CAMERA_Y - 1.0f, DEFAULT_CAMERA_Y + 0.6f);

  fm_vec3_t inputVector = {{ xInput, yInput, 0.0f }};
  fm_vec3_norm(&inputVector, &inputVector);

  // get forward angle
  float xTarget = cos(player.cameraAngle);
  float zTarget = sin(player.cameraAngle);

  // get perpendicular angle
  float perpXTarget = cos(player.cameraAngle + M_PI * 0.5f);
  float perpZTarget = sin(player.cameraAngle + M_PI * 0.5f);

  // UPDATE CAMERA

  // combine forward/back input + forward angle AND left/right input + perp angle
  float zChange = (inputVector.y * zTarget) + (inputVector.x * perpZTarget);
  float xChange = (inputVector.y * xTarget) + (inputVector.x * perpXTarget);

  // normalize input, so angular movement isn't doubled
  fm_vec3_t posChange = {{ xChange, 0, zChange }};
  fm_vec3_norm(&posChange, &posChange);

  // get some sort of camera motion
  if (posChange.x != 0 || posChange.z != 0) {
    player.movementTally += 0.01f;
  }
  float yOffset = stepHeight * sin(player.movementTally * 10.0f);


  // detect collision
  float nextFrameZ = player.position.z + posChange.z * player.movementSpeed;
  fm_vec3_t changeVectorZ = {{ player.position.x, player.position.y, nextFrameZ }};

  // revert z movement if colliding
  if (player_detect_collisions(&changeVectorZ)) {
    nextFrameZ -= posChange.z * player.movementSpeed;
  }

  float nextFrameX = player.position.x + posChange.x * player.movementSpeed;
  fm_vec3_t changeVectorX = {{ nextFrameX, player.position.y, nextFrameZ }};

  // revert x movement if colliding
  if (player_detect_collisions(&changeVectorX)) {
    nextFrameX -= posChange.x * player.movementSpeed;
  }
  
  // apply position
  player.position.z = nextFrameZ;
  player.position.x = nextFrameX;
  player.position.y = DEFAULT_CAMERA_Y + yOffset;

  // apply camera target
  player.cameraTarget.x = player.position.x + (xTarget * 2.0f);
  player.cameraTarget.y = player.cameraY + yOffset;
  player.cameraTarget.z = player.position.z + (zTarget * 2.0f);


  if (yOffset <= stepHeight * -0.9f && !player.hasStepped) {
    // p_audio_play_SFX(SFX_STEP);
    player.hasStepped = true;
  } else if (yOffset >= stepHeight * -.9f && player.hasStepped) {
    player.hasStepped = false;
  }
}

void player_handle_interaction(void) {
  joypad_buttons_t pressedButtons = joypad_get_buttons_pressed(0);

  if (player.closestEntity != NULL) {
    if (pressedButtons.a) {
      player.closestEntity->interact(player.closestEntity);
    }
  } else {
    // handle using item
  }

  if (pressedButtons.b) {
    player.currentItem = inventory_get_next_unlocked_item(player.currentItem);
  }

  if (pressedButtons.a) {
    debugf(player_detect_collisions(&player.position) ? "colliding\n" : "not colliding\n");
  }
}

// RESOLUTION_320x240
void player_draw_ui(void) {

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
}

void player_detect_closest_entity (void) {
  State *state = getState();

  // float closestDistance = 1000;
  struct Entity *closestEntity = NULL;

  struct Entity *entities = state->activeLevel->activeScene->entities;
  for (int i = 0; i < state->activeLevel->activeScene->entityCount; i++) {
    // move distance logic here
    if (entities[i].canInteract(&entities[i])) {
      closestEntity = &entities[i];
    }
  }
  player.closestEntity = closestEntity;
}

fm_vec3_t rotate_vector_by_inverse_quaternion(fm_vec3_t *point, float quaternion[4]) {
    // Conjugate of a unit quaternion flips the signs of the vector components (x, y, z).
    // The scalar component (w) stays positive.
    float qw =  quaternion[0];
    float qx = -quaternion[1];
    float qy = -quaternion[2];
    float qz = -quaternion[3];

    // Precalculate cross product components: (q_xyz X v)
    float cx = qy * point->z - qz * point->y;
    float cy = qz * point->x - qx * point->z;
    float cz = qx * point->y - qy * point->x;

    // Add scaling by the scalar w: (q_xyz X v) + w * v
    cx += qw * point->x;
    cy += qw * point->y;
    cz += qw * point->z;

    fm_vec3_t final;

    // Calculate final out vector: v + 2 * (q_xyz X intermediate_vector)
    final.x = point->x + 2.0f * (qy * cz - qz * cy);
    final.y = point->y + 2.0f * (qz * cx - qx * cz);
    final.z = point->z + 2.0f * (qx * cy - qy * cx);

    return final;
}

bool player_detect_collisions(fm_vec3_t *point) {
  State *state = getState();
  Scene *scene = state->activeLevel->activeScene;

  for (int32_t i = 0; i < scene->colliderCount; i++) {
    Collider collider = scene->colliders[i];
    debugf("\n*** %i type %i ***\n", (int)i, collider.type);
    if (collider.type == COLLIDER_AABB && collision_aabb_2d(point, collider.aabbMin, collider.aabbMax)) {
      return true;
    } else if(collider.type == COLLIDER_OBB) {
      // apply reverse transformation to player
      // fm_vec3_t transformedPoint;
      // fm_vec3_t collisionBoxPosition = {{ collider.pos[0], collider.pos[1], collider.pos[2] }};
      // fm_vec3_sub(&transformedPoint, point, &collisionBoxPosition);

      // apply reverse rotation to player
      // fm_vec3_t rotatedPoint = rotate_vector_by_inverse_quaternion(&transformedPoint, collider.rot);

      // debugf("%f/%f/%f \n", collider.pos[0], collider.pos[1], collider.pos[2]);
      // debugf("%f/%f \n", point->x, point->z);
      // debugf("%f/%f \n", transformedPoint.x, transformedPoint.z);
      // debugf("%f/%f \n", rotatedPoint.x, rotatedPoint.z);
      // debugf("-- %f/%f \n", collider.scale[0], collider.scale[2]);
      // if (fabsf(rotatedPoint.x) > collider.scale[0]) return true;
      // if (fabsf(rotatedPoint.y) > collider.scale[1]) return true;
      // if (fabsf(rotatedPoint.z) > collider.scale[2]) return true;
      // fm_vec3_t aabbMin = (fm_vec3_t){{ -(collider.scale[0]), 0, -(collider.scale[2]) }};
      // fm_vec3_t aabbMax = (fm_vec3_t){{ +(collider.scale[0]), 0, +(collider.scale[2]) }};
      // debugf("%f/%f\n", aabbMin.x, aabbMin.z);
      // debugf("%f/%f\n", aabbMax.x, aabbMax.z);

      // state->debugPos[0] = aabbMax.x; // = (float[3]){aabbMin.x, aabbMin.y, aabbMin.z};
      // state->debugPos[1] = aabbMax.y; // = (float[3]){aabbMin.x, aabbMin.y, aabbMin.z};
      // state->debugPos[2] = aabbMax.z; // = (float[3]){aabbMin.x, aabbMin.y, aabbMin.z};

      // if (collision_aabb_2d(&rotatedPoint, aabbMin, aabbMax)) {
      //   return true;
      // }

      // fm_vec3_dot()

      // fm_vec3_t pointA;
      // fm_vec3_t noWRot = { collider.rot[1], collider.rot[2], collider.rot[3] };
      // float scalar = collider.rot[0];

      // fm_vec3_mul

      // fm_vec3_t rotatedPoint = 2.0f * fm_vec3_dot(&noWRot, &pointA) * noWRot
      //                          + (scalar*scalar - dot(noWRot, noWRot)) * pointA
      //                          + 2.0f * scalar * fm_vec3_cross(&noWRot, &pointA);

      // move player point to local transform (point = point - collider pos)
        // when the player is on top of the collider, this point should be 0
      // get two points for each axis (x/z) -> so (pos.x) + scale.x and (pos.x) - scale.x
      // apply collider's rotation to those points, and then use that x??? / z???
      // if x is within those x and y is within those y, you're colliding
    }
  }


  // change the player's position by the collider (so the collider is "at" 0,0,0)

  // un-rotate the point in relation to the OBB
  
  
  // do a more normal AABB range check against the box


  // can I do like, raycast from movement and downwards. if it hits a triangle, check the normal of that triangle
  // depending on the normal, adjust player speed
  return false;
}

bool player_raycast_for_floor(void) {
  // start at player 0 (I guess we have to define a player height first)
  // march the ray downwards (y - interval)
  // loop through each active level's floors
    // if the ray's y is close to the floor's y (define a margin somewhere)
      // do an aabb check on the ray's x/z against the floor's min/max
        // if inside, then return true?
        // else return false
  return true;
}

// todo:
// - throw seed
// - pet pigeon
// - collect golden feathers
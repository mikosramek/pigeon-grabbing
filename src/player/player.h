#ifndef PLAYER_H
#define PLAYER_H

#include <libdragon.h>
#include <t3d/t3d.h>
#include <math.h>
#include "../utils/pigeon_math.h"
#include "../utils/pigeon_audio.h"

typedef struct {
  float cameraY;
  float cameraAngle;
  fm_vec3_t position;
  fm_vec3_t cameraTarget;
  uint32_t movementSpeed;
  float cameraRotationSpeed;
} Player;

Player *getPlayer(void);

void resetPlayer(void);

void updatePlayer(void);


#endif
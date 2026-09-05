#ifndef PIGEON_MATH_H
#define PIGEON_MATH_H

#include "libdragon.h"

float min(float number, float minNum);
float max(float number, float maxNum);
float clamp(float number, float minNum, float maxNum);

bool collision_aabb_2d(fm_vec3_t *point, fm_vec3_t interactionMin, fm_vec3_t interactionMax);

#endif
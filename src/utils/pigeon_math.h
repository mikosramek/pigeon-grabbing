#ifndef PIGEON_MATH_H
#define PIGEON_MATH_H

#include "libdragon.h"

float min(float number, float minNum);
float max(float number, float maxNum);
float clamp(float number, float minNum, float maxNum);

bool collision_aabb_2d(fm_vec3_t *point, fm_vec3_t interactionMin, fm_vec3_t interactionMax);
void rotate_vec2_by_quat(float point[3], float quat[4], float point_out[3]);
void normalize_quat(float quat_in[4], float quat_out[4]);

#endif
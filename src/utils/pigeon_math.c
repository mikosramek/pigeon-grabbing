#include "pigeon_math.h"

float min(float number, float minNum) {
  if (number < minNum) {
    return minNum;
  }
  return number;
}

float max(float number, float maxNum) {
  if (number > maxNum) {
    return maxNum;
  }
  return number;
}

float clamp(float number, float minNum, float maxNum) {
  return max(min(number, minNum), maxNum);
}

bool collision_aabb_2d(fm_vec3_t *point, fm_vec3_t interactionMin, fm_vec3_t interactionMax) {
  bool xAligned = point->x >= interactionMin.x && point->x <= interactionMax.x;
  bool zAligned = point->z >= interactionMin.z && point->z <= interactionMax.z;
  return xAligned && zAligned;
}
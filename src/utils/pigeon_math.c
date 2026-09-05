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

bool collision_aabb_2d(fm_vec3_t point, int interactionMin[3], int interactionMax[3]) {
  bool xAligned = point.x >= interactionMin[0] && point.x <= interactionMax[0];
  bool zAligned = point.z >= interactionMin[2] && point.z <= interactionMax[2];
  return xAligned && zAligned;
}
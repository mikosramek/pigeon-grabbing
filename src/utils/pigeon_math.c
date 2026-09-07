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

void rotate_vec2_by_quat(float point[3], float quat[4], float point_out[3]) {
  float quat_x = quat[0];
  float quat_y = quat[1];
  float quat_z = quat[2];
  float quat_w = quat[3];
  float point_x = point[0];
  float point_y = point[1];
  float point_z = point[2];

  float tx = 2.0f * (quat_y * point_z - quat_z * point_y);
  float ty = 2.0f * (quat_z * point_x - quat_x * point_z);
  float tz = 2.0f * (quat_x * point_y - quat_y * point_x);

  point_out[0] = point_x + quat_w * tx + (quat_y * tz - quat_z * ty);
  point_out[1] = point_y + quat_w * ty + (quat_z * tx - quat_x * tz);
  point_out[2] = point_z + quat_w * tz + (quat_x * ty - quat_y * tx);
}

void normalize_quat(float quat_in[4], float quat_out[4]) {
  float len = sqrtf(
    quat_in[0] * quat_in[0] +
    quat_in[1] * quat_in[1] +
    quat_in[2] * quat_in[2] +
    quat_in[3] * quat_in[3]
  );

  quat_out [0] = quat_in[0] / len;
  quat_out [1] = quat_in[1] / len;
  quat_out [2] = quat_in[2] / len;
  quat_out [3] = quat_in[3] / len;
}
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

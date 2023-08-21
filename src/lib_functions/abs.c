#include "../realized_math.h"

int realized_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}
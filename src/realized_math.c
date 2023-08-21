#include "realized_math.h"

int realized_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double realized_fabs(double x) {
  if (x < 0.0) {
    x *= -1.0;
  }
  return (long double)x;
}

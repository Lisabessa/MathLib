#include "../realized_math.h"

long double realized_atan(double x) {
  long double result = 0;
  if (x == -realized_INF) {
    result = -realized_PI / 2;
  } else if (x == realized_INF) {
    result = realized_PI / 2;
  } else {
    result = realized_asin(x / realized_sqrt(1.0 + x * x));
  }
  return result;
}

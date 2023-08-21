#include "../realized_math.h"

long double realized_tan(double x) {
  long double result = 0;
  if (realized_fabs(x) == realized_PI / 2) {
    result = realized_TAN_PI_2 * ((x < 0) ? -1 : 1);
  } else {
    result = realized_sin(x) / realized_cos(x);
  }
  return result;
}
#include "../realized_math.h"

long double realized_acos(double x) {
  long double res = realized_NAN;

  if (realized_fabs(x) <= 1) {
    res = realized_PI / 2 - realized_asin(x);
  }
  return res;
}

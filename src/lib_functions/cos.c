#include "../realized_math.h"

long double realized_cos(double x) {
  long double result = 0;
  if (!realized_is_nan(x) && !realized_is_inf(x) && realized_fabs(realized_sin(x)) < 1) {
    result = realized_sin((realized_PI / 2) - x);
  } else if (realized_is_nan(x)) {
    result = realized_NAN;
  } else if (realized_is_inf(x)) {
    result = -realized_NAN;
  }

  return result;
}
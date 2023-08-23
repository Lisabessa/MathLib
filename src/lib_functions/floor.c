#include "../realized_math.h"

long double realized_floor(double x) {
  long double result;
  if (x == realized_INF || realized_is_nan(x)) {
    result = x;
  } else if (x == -realized_INF) {
    result = -realized_INF;
  } else if (x == 0.0) {
    result = 0.0;
  } else if (x == -0.0) {
    result = -0.0;
  } else {
    long double integer_part = (long double)((long long)x);
    if (integer_part == x) {
      result = integer_part;
    } else if (x < 0.0 && realized_fabs(integer_part - x) <= 1) {
      result = integer_part - 1.0;
    } else if (integer_part >= 0 || realized_fabs(integer_part - x) <= 1) {
      result = integer_part;
    } else {
      result = x;
    }
  }
  return result;
}
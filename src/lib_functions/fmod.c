#include "../realized_math.h"

long double realized_fmod(double x, double y) {
  long double result = 0;
  if (realized_is_nan(x) || realized_is_nan(y) || realized_is_inf(x) || y == 0) {
    result = realized_NAN;
  } else if (x == 0 && y != 0 && !realized_is_nan(y)) {
    result = 0;
  } else if (x != realized_INF && x != -realized_INF && (y == realized_INF || y == -realized_INF)) {
    result = x;
  } else {
    long long q = x / y;
    result = x - q * y;
  }
  return result;
}
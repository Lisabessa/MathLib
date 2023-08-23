#include "../realized_math.h"

long double realized_ceil(double x) {
  long long integer_part = (long long)x;
  long double result;
  if (x == realized_INF) {
    result = realized_INF;
  } else if (x == -realized_INF) {
    result = -realized_INF;
  } else if (x == 0) {
    result = 0;
  } else if (x == -0) {
    result = -0;
  } else if (x > 0 && x > integer_part && integer_part >= 0) {
    result = (long double)(integer_part + 1);
  } else if (x < 0 && x < integer_part && integer_part - x <= 1) {
    result = (long double)integer_part;
  } else {
    result = x;
  }
  return result;
}

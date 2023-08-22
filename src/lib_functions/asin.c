#include "../realized_math.h"

long double realized_asin(double x) {
  double t = x;
  long double sum = realized_NAN;

  if (realized_fabs(x) < 1) {
    sum = t;
    x *= x;
    long iterations = 0;
    for (int n = 1; realized_fabs(t) > realized_EPSILON && iterations <= 100000000;
         n += 2, iterations++)
      sum += (t *= x * n / (n + 1)) / (n + 2);
  } else if (x == 1) {
    sum = realized_PI / 2;
  } else if (x == -1) {
    sum = -realized_PI / 2;
  }
  return sum;
}
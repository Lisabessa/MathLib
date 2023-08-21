#include "../realized_math.h"

long double realized_sin(double x) {
  x = realized_fmod(x, 2.0 * realized_PI);
  double result = 0.0;
  double term = x;
  double sign = 1.0;
  double factorial = 1.0;

  for (int n = 1; n <= 15; n++) {
    result += sign * term;
    term *= x * x / ((2 * n) * (2 * n + 1));
    sign *= -1.0;
    factorial *= (2 * n) * (2 * n + 1);
  }

  return result;
}
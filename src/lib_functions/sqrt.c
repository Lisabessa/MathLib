#include "../realized_math.h"

long double realized_sqrt(double x) {
  long double n = x;
  long double root;

  if (x > 0) {
    if (realized_is_inf(x)) {
      root = realized_INF;
    } else {
      while (1) {
        root = 0.5 * (n + (x / n));
        if (realized_fabs(root - n) < realized_EPSILON) {
          break;
        }
        n = root;
      }
    }
  } else if (x == 0) {
    root = 0;
  } else {
    root = realized_NAN;
  }
  return root;
}

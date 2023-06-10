#include <stdio.h>
#include <stdlib.h>

#define realized_NAN (0.0 / 0.0)
#define realized_INF (1.0 / 0.0)
#define realized_TOLERANCE 1e-6
#define realized_PI 3.14159265358979323846
#define realized_E 2.7182818284590452354
#define realized_EPSILON (long double)1e-11
#define realized_DMAX 1.7976931348623157E+308
#define realized_DMIN -1.7976931348623157E+308
#define realized_TAN_PI_2 16331239353195370.000000

// Computes absolute value of an integer value
int realized_abs(int x);

// Computes absolute value of a floating-point value
long double realized_fabs(double x);

// Computes square root
long double realized_sqrt(double x);

// Raises a number to the given power
long double realized_pow(double base, double exp);

// Returns e raised to given power
long double realized_exp(double x);

// Returns the nearest integer not less than the given value
long double realized_ceil(double x);

// Returns the nearest integer not greater than the given value
long double realized_floor(double x);

// Remainder of the floating-point division operation
long double realized_fmod(double x, double y);

// Computes sine
long double realized_sin(double x);

// Computes cosine
long double realized_cos(double x);

// Computes tangent
long double realized_tan(double x);

// Computes arc sine
long double realized_asin(double x);

// Computes arc cosine
long double realized_acos(double x);

// Computes arc tangent
long double realized_atan(double x);

// Computes natural logarithm
long double realized_log(double x);

// Checks if x is infinite
int realized_isinf(double x);

// Checks if x is NaN
int realized_isnan(double x);

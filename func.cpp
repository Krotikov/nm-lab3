#include "func.h"

double mypow(double x, unsigned n) {
  double res = 1;
  for (unsigned i = 0; i < n; ++i)
    res *= x;

  return res;
}

double Func(double x) {
  double res = mypow(x, 5) - 8.2 * mypow(x, 3) + 4.5 * mypow(x, 2) - 7 * x + 6.5;
  return res;
}

double AntiDer(double x) {
  double res = (1.0 / 6) * mypow(x, 6) - 2.05 * mypow(x, 4) + 1.5 * mypow(x, 3) - 3.5 * x * x + 6.5 * x;
  return res;
}

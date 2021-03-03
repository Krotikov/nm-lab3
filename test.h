#ifndef TEST_H
#define TEST_H

#include "trapezoid.h"
#include <fstream>

#define LBORD -3.3
#define RBORD 0.9
#define MAX_EPS 1e-9
#define MIN_EPS 1e-1

void Test(double (*func)(double), double (*antiDer)(double));
/*
Creates 3 files
X: from 1e-1 to 1e-9, xi+1 = xi*sqrt(1e-1)
Y: exactVal - calcVal
Z: amount of separations (numOfPoints = 2^n) and I save (n)
*/

#endif /* TEST_H */
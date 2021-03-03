#include "test.h"

void Test(double (*func)(double), double (*antiDer)(double)) {
  double lbord = LBORD;
  double rbord = RBORD;
  double eps = MAX_EPS;
  double min = MIN_EPS;
  double de = sqrt(1e-1);
  double a = AntiDer(lbord);
  double b = AntiDer(rbord);

  std::ofstream xout, yout, zout;

  xout.open("eps(x).txt");
  yout.open("epsFact(y).txt");
  zout.open("numReps(y).txt");

  for (double tmp = min; tmp > eps; tmp *= de) {
    int count = 0;
    Trapezoid trap(lbord, rbord, &Func);
    double res = trap.calcModif(tmp, &count);

    xout << tmp << " ";
    yout << fabs(res - b + a) << " ";   //res - b + a = res - (b - a), b - a = exact value of integral
    zout << count << " ";
  }

  xout.close();
  yout.close(); 
  zout.close();

  return;
}

#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "func.h"


struct Trapezoid {
  Trapezoid(double lbord, double rbord, double (*func)(double)){
    this->lbord = lbord;
    this->rbord = rbord;
    this->func = func;
  }

  double calc(double eps, int* count);

  double calcModif (double eps, int* count);

  double calc(double eps);


  ~Trapezoid() {}
  
  double lbord;
  double rbord; 
  double (*func)(double);
};

#endif /*TRAPEZOID_H*/
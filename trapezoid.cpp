#include "trapezoid.h"

//TODO: fix calc because this algorithm has some problems

double Trapezoid::calc(double eps, int* count){
  double len = rbord - lbord;
  double integVal = (func(lbord) + func(rbord)) * len / 2;
  double err = 0;
  int numReps = 0;
  int n = 1;
  
  do{
    double newLen = len / 2.0;
    double integValPrev = integVal;
    double tmp = lbord;

    numReps += n;
    integVal = 0;
    
    for (int i = 0; i < numReps; ++i) {
      integVal += (func(tmp) + func(tmp + newLen)) * newLen / 2.0;
      tmp += newLen;
    }

    err = (integVal - integValPrev) / 3.0;
    n = 2 * n;
    len = newLen;

    (*count)++;
  } while (fabs(err) >= eps);

  return integVal + err;
}

double Trapezoid::calcModif(double eps, int* count) {
  int n = 1;
  double len = rbord - lbord;
  double integVal = (func(lbord) + func(rbord)) * len / 2.0;
  double err = 0;

  do {
    double newLen = len / 2;
    double integValPrev = integVal;
    double tmp = lbord + newLen;

    integVal = 0;
    for (int i = 0; i < n; ++i) {
      integVal += func(tmp);
      tmp += len;
    }
    integVal *= len;
    integVal = (integVal + integValPrev) / 2.0;

    err = (integVal - integValPrev) / 3.0;

    n = 2 * n;
    len = newLen;
    (*count)++;
    
  } while (fabs(err) >= eps);

  return integVal; // +err;
}

double Trapezoid::calc(double eps) {
  int n = 1;
  double len = rbord - lbord;
  double integVal = (func(lbord) + func(rbord)) * len / 2.0;
  double err = 0;

  do {
    double newLen = len / 2;
    double integValPrev = integVal;
    double tmp = lbord + newLen;

    integVal = 0;
    for (int i = 0; i < n; ++i) {
      integVal += func(tmp);
      tmp += len;
    }
    integVal *= len;
    integVal = (integVal + integValPrev) / 2.0;

    err = (integVal - integValPrev) / 3.0;

    n = 2 * n;
    len = newLen;
    //integVal += err;

  } while (fabs(err) >= eps);

  return integVal;
 }
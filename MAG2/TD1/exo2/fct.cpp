#include "fct.h"
#include<iostream>
#include<cmath>
using namespace std;
void affiche(double a, double b) {
  cout << a << "+" << "i" << b <<endl;
}
double norme(double x, double y) {
  double nrm;
  nrm=pow(x*x+y*y, 0.5);
  return nrm;
}
double argument(double x, double y) {
  double nrm;
  nrm=pow(x*x+y*y, 0.5);
  double angle1 = acos(x/nrm);
  double angle2 = asin(y/nrm);
  if (angle1==angle2) {
    return angle1;
  }
  else {
    return -angle1;
  }
}

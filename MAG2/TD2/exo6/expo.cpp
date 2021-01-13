#include "complexe.h"
#include<iostream>
#include<cmath>
using namespace std;
void complexe::initialise(double a, double b) {
  re=a;
  im=b;
}
void complexe::affiche() {
  cout << re << "+" << "i" << im <<endl;
}
double complexe::module() {
  double nrm;
  nrm=pow(re*re+im*im, 0.5);
  return nrm;
}
double complexe::argument() {
  double nrm;
  nrm=pow(re*re+im*im, 0.5);
  if(re==0) {
    if(im<0) {
      return -M_PI_2;
    } else {
      return M_PI_2;
    }
  }
  if(re>0) {
    return atan(im/re);
  } else {
    if(im>0) {
      return atan(im/re) + M_PI;
    } else {
      return atan(im/re) - M_PI;
    }
  }
}

    

    

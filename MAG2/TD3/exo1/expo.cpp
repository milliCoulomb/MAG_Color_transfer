#include "complexe.h"
#include<iostream>
#include<cmath>
using namespace std;

complexe::complexe()
  : re(0.0), im(0.0)
{
}
complexe::complexe(double re_, double im_)
  : re(re_), im(im_)
{
}

void complexe::affiche() {
  cout << re << "+" << "i" << im <<endl;
}
double complexe::norme() {
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
double complexe::get_re() const {
  return re;
}
double complexe::get_im() const {
  return im;
}
void complexe::set_re(double re_) {
  re=re_;
}
void complexe::set_im(double im_) {
  im=im_;
}

    

    

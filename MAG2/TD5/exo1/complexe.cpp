#include "complexe.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
complexe::complexe(const double re_, const double im_)
  : re(re_), im(im_)
{
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
complexe operator+(complexe a, complexe b)
{
  return complexe(a.re + b.re, a.im + b.im);}
complexe operator*(complexe a, complexe b)
{
  return complexe(a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re);}
complexe & complexe::operator=(const complexe & autre) {
  re = autre.re;
  im = autre.im;
  return *this;
}
ostream & operator<<(ostream & out, const complexe & nombre)
{
  if (nombre.get_im() < 0) {
    out << nombre.get_re() << "-" << -nombre.get_im() << "i";
  }
  else {
    out << nombre.get_re() << "+" << nombre.get_im() << "i";
  }
  return out;
}

    

    

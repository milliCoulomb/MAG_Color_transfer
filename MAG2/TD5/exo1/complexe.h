#ifndef complexe_H
#define complexe_H
#include<iostream>
#include<ostream>
using namespace std;
class complexe
{
 private :
  double re;
  double im;
 public :
  complexe(const double re_, const double im_);
  friend complexe operator+ (complexe a, complexe b);
  friend complexe operator*(complexe a, complexe b);
  complexe & operator=(const complexe & autre);
  friend ostream & operator<<(ostream & out, const complexe & nombre);
  double get_re() const;
  double get_im() const;
  void set_re(const double re_);
  void set_im(const double im_);
  void affiche();
  double argument();  
  double module();
};
#endif



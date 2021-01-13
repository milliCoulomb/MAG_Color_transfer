#ifndef complexe_H
#define complexe_H
#include<iostream>
using namespace std;
class complexe
{
 private :
  double re;
  double im;
 public :
  double get_re() const;
  double get_im() const;	 
  void set_re(double re_);
  void set_im(double im_);
  void affiche();
  double argument();
  double norme();
  complexe();
  complexe(double re_, double im_);
};
#endif



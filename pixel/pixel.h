#ifndef _PIXEL_H_
#define _PIXEL_H_
#include<iostream>
#include<ostream>
#include<cmath>
#include"matrix.h"
using namespace std:
class pixel : public matrix
{
 private :
  double p_red;
  double p_green;
  double p_blue;
  int lines=3;
  int rows=1;
 public :
  pixel();
  ~pixel();
  double get_red() const;
  double get_green() const;
  double get_blue() const;
  void set_red(const double red);
  void set_green(const double green);
  void set_blue(const double blue);
  pixel LMS() const;
  pixel LAB() const;
 };
#endif //_PIXEL_H_

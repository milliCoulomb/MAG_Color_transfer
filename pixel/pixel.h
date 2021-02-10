#ifndef _PIXEL_H_
#define _PIXEL_H_
#include<iostream>
#include<ostream>
#include<cmath>
#include"matrix.h"
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
  //~pixel();
  int get_lines() const;
  int get_rows() const;
  double get_red() const;
  double get_green() const;
  double get_blue() const;
  void set_red(const double red);
  void set_green(const double green);
  void set_blue(const double blue);
  void LMS() const;
  void LAB() const;
  void back_to_LMS_from_LAB() const;
  void back_to_RGB_from_LMS() const;
 };
#endif //_PIXEL_H_

#ifndef _PIXEL_H_
#define _PIXEL_H_
#include<iostream>
#include<ostream>
#include<cmath>
#include"matrix.h"
class pixel : public matrix
{
 private :
  int lines=3;
  int rows=1;
 public :
  pixel();
  ~pixel();
  int get_lines() const;
  int get_rows() const;
  double RLl() const;
  double GMa() const;
  double BSb() const;
  void LMS() const;
  void LAB() const;
  void back_to_LMS_from_LAB() const;
  void back_to_RGB_from_LMS() const;
 };
#endif //_PIXEL_H_

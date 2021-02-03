#ifndef _PIXEL_H_
#define _PIXEL_H_
#include<iostream>
#include<ostream>
#include"Classematrice.h"
using namespace std:
class pixel : public matrice
{
 private :
  int p_red;
  int p_green;
  int p_blue;
  int NBlines=3;
  int NBcol=0;
 public :
  pixel();
  ~pixel();
  int get_red() const;
  int get_green() const;
  int get_blue() const;
  void set_red(int red);
  void set_green(int green);
  void set_blue(int blue);
  
 
 
    
#endif //_PIXEL_H_

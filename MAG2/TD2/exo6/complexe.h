#ifndef complexe_H
#define complexe_H
#include<iostream>
using namespace std;
class complexe
{
 public :
  double re;
  double im;
  void affiche();
  void initialise(double x, double y);
  double argument();  
  double module();
};
#endif



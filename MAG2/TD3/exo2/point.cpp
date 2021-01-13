#include<iostream>
#include<cmath>
using namespace std;
#include "classe_p.h"
point::point()
  : abs(0.0), ord(0.0)
{
}
point::point(double abs_, double ord_)
  : abs(abs_), ord(ord_)
{
}
void point::affiche()
{
  cout << abs << " et " << ord <<endl;
}
double point::module()
{
  return pow(abs*abs+ord*ord,0.5);
}
double point::get_abs() const {
  return abs;
}
double point::get_ord() const {
  return ord;
}
void point::set_abs(double abs_) {
  abs=abs_;
}
void point::set_ord(double ord_) {
  ord=ord_;
}

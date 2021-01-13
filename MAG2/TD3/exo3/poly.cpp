#include<iostream>
#include<cmath>
using namespace std;
#include "classe_poly.h"
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
void poly::set_ordre(int ordre_) {
  ordre=ordre_;
}
double poly::get_ordre() const {
  return ordre;
}
void poly::poly_affiche()
{
  for (int i=0; i<ordre; i++) {
    mes_points[i].affiche();
  }
}
double poly::perimetre()
{
  double perim=0;
  double w,x,y,z;
  for (int i=0; i<ordre-1; i++) {
    w=mes_points[i].get_abs();
    x=mes_points[i].get_ord();
    y=mes_points[i+1].get_abs();
    z=mes_points[i+1].get_ord();
    perim += pow((w-y)*(w-y) + (x-z)*(x-z), 0.5);
  }
  w=mes_points[0].get_abs();
  x=mes_points[0].get_ord();
  y=mes_points[ordre].get_abs();
  z=mes_points[ordre].get_ord();
  perim += pow((w-y)*(w-y) + (x-z)*(x-z), 0.5);
  return perim;
}
void poly::set_mespoints(point* mes_points_) {
  *mes_points = *mes_points_;
}
point poly::get_mespoints() const {
  return *mes_points;
}
poly::poly(int ordre_, vector<vector<double>> mes_points_) {
  ordre=ordre_;
  mes_points = new point[ordre];
  for (int i =0; i<ordre; i++) {
    point finale(mes_points_[0][i], mes_points_[1][i]);
    mes_points[i]=finale;
  }
}



    
    

    

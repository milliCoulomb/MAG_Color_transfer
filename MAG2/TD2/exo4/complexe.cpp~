#include<iostream>
#include<cmath>
using namespace std;
#include "classe_poly.h"
void point::affiche()
{
  cout << abs << " et " << ord <<endl;
}
void point::initialise(double x, double y)
{
  abs=x;
  ord=y;
}
double point::module()
{
  return pow(abs*abs+ord*ord,0.5);
}
void poly::initialise_poly(int n, vector<vector<double>> points)
{
  ordre=n;
  mes_points = new point[ordre];
  for (int i =0; i<ordre; i++) {
    mes_points[i].initialise(points[0][i], points[1][i]);
  }
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
    w=mes_points[i].abs;
    x=mes_points[i].ord;
    y=mes_points[i+1].abs;
    z=mes_points[i+1].ord;
    perim += pow((w-y)*(w-y) + (x-z)*(x-z), 0.5);
  }
  w=mes_points[0].abs;
  x=mes_points[0].ord;
  y=mes_points[ordre].abs;
  z=mes_points[ordre].ord;
  perim += pow((w-y)*(w-y) + (x-z)*(x-z), 0.5);
  return perim;
}
    
    

    

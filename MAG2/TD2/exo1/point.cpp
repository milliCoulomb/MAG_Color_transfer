#include<iostream>
#include<cmath>
using namespace std;
#include "classe_p.h"
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
  return sqrt(abs*abs + ord*ord);
}

#include<iostream>
#include<cmath>
using namespace std;
#include "classe_poly.h"
int main() {
  poly mon_poly;
  vector<vector<double>> vc(2, vector<double>());
  vc[0].push_back(1);
  vc[1].push_back(1);
  vc[0].push_back(2);
  vc[1].push_back(2);
  vc[0].push_back(0);
  vc[1].push_back(1.5);
  mon_poly.initialise_poly(3, vc);
  mon_poly.poly_affiche();
  cout << mon_poly.perimetre() <<endl;
  return (0);
}

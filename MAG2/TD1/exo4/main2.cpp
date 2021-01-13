#include<iostream>
#include<cmath>
#include"fct.h"
using namespace std;
int main() {
  double a = 1;
  double b = 1;
  double & res_a = a;
  double & res_b = b;
  double* res_ap = &a;
  double* res_bp = &b;
  expo_par_ref(a,b,res_a,res_b);
  expo_par_adresse(a,b,res_ap,res_bp);
  cout << res_a << " " << res_b << endl;
  cout << *res_ap << " " << *res_bp << endl;
  return 0;
}

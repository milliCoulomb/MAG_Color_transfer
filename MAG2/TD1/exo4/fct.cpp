#include<iostream>
#include<cmath>
void expo_par_ref(double a, double b, double & res_a, double & res_b) {
  res_a = exp(a)*(cos(b));
  res_b = exp(a)*(sin(b));
}
void expo_par_adresse(double a, double b, double* res_a, double* res_b) {
  *res_a = exp(a)*(cos(b));
  *res_b = exp(a)*(sin(b));
}
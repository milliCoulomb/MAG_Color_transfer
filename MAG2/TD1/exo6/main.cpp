#include<iostream>
#include<cmath>
#include"fct.h"
using namespace std;
int main() {
  int n,i,j;
  cout << "n=";
  cin >> n;
  double *real = new double[n];
  double *imag = new double[n];
  for (i=0; i<=n-1; i++) {
    expo(0, 2*i*M_PI/n, real[i], imag[i]);
  }
  double re_sum = 0;
  double im_sum = 0;
  for (j=0; j<=n-1; j++) {
    re_sum += real[j];
    im_sum += imag[j];
  }
  cout << re_sum << "et " << im_sum <<endl;
  return 0;
}

#include<iostream>
#include<cmath>
#include<vector>
#include"complexe.h"
using namespace std;
complexe expc(complexe cplx) {
  double a,b;
  a=exp(cplx.re)*cos(cplx.im);
  b=exp(cplx.re)*sin(cplx.im);
  complexe res;
  res.initialise(a,b);
  return res;
}
int main() {
  complexe mon_complexe, expo;
  int N=1000;
  vector<complexe> monTableau;
  for (int i; i<N; i++) {
    complexe cplx;
    cplx.initialise(0, 2*M_PI*i/N);
    complexe t = expc(cplx);
    monTableau.push_back(t);
  }
  double S1, S2;
  S1=0;
  S2=0;
  for (int j; j<N; j++) {
    complexe inter;
    inter = monTableau[j];
    double a,b;
    a=inter.re;
    b=inter.im;
    S1+= a;
    S2+= b;
  }
  cout << S1 << endl;
  cout << S2 << endl;
  return 0;
}

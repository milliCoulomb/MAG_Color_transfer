#include<iostream>
#include<cmath>
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
  mon_complexe.initialise(1,6);
  mon_complexe.affiche();
  expo=expc(mon_complexe);
  cout << mon_complexe.module() << endl;
  cout << mon_complexe.argument() << endl;
  expo.affiche();
  cout << expo.module() << endl;
  cout << expo.argument() << endl;
  return 0;
}

#include<iostream>
#include<ostream>
#include"complexe.h"
using namespace std;
int main() {
  complexe cplx1(1,9);
  complexe cplx2(5,2);
  complexe cplx3(0,0);
  complexe cplx4(0,0);
  cplx1.affiche();
  cplx2.affiche();
  cplx3 = cplx1 + cplx2;
  cplx4 = cplx1*cplx2;
  cplx3.affiche();
  cplx4.affiche();
  cout << cplx1 <<endl;
  return 0;
}

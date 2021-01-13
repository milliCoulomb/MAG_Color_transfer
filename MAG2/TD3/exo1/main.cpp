#include<iostream>
#include"complexe.h"
using namespace std;
int main() {
  complexe mon_complexe(1,1);
  complexe my_complex;
  mon_complexe.affiche();
  cout << mon_complexe.norme() << endl;
  cout << mon_complexe.argument() << endl;
  my_complex.affiche();
  cout << my_complex.norme() << endl;
  cout << my_complex.argument() << endl;
  return 0;
}

#include<iostream>
#include"complexe.h"
using namespace std;
int main() {
  complexe mon_complexe;
  mon_complexe.initialise(0,1);
  mon_complexe.affiche();
  cout << mon_complexe.module() << endl;
  cout << mon_complexe.argument() << endl;
  return 0;
}

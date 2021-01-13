#include<iostream>
#include"fct.h"
using namespace std;
int main() {
  double x = 0.5;
  double y = 0.866025;
  affiche(x,y);
  cout << norme(x,y) << endl;
  cout << argument(x,y) << endl;
  return 0;
}

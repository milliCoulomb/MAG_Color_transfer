#include<iostream>
using namespace std;
#include "classe_p.h"
int main() {
  point mon_point(1,2);
  point mon_zero;
  mon_zero.affiche();
  mon_point.affiche();
  cout << mon_point.module() << endl;
  cout << mon_zero.module() << endl;
  return 0;
}
  
  

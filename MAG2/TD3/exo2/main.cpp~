#include<iostream>
using namespace std;
#include "classe_p.h"
int main() {
  int i;
  int indice=0;
  point mon_point;
  point* tab = new point[5];
  tab[0].initialise(1,2);
  tab[1].initialise(45,100);
  tab[2].initialise(-1,-20);
  tab[3].initialise(15,0);
  tab[4].initialise(-108,26);
  double min=tab[0].module();
  for (i=0; i<5; i++) {
    tab[i].affiche();
    if (tab[i].module() < min) {
      min=tab[i].module();
      indice=i;
    }    
  }
  cout << min <<endl;
  tab[indice].affiche();
  return 0;
}
  
  

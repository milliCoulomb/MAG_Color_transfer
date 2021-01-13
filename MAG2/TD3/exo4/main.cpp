#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#include"classe_hasard.h"
void TestObjet(hasard A) {
  cout << "Ceci est une phrase random" << endl;
}
int main() {
  srand(time(0));
  hasard hA(10, 8);
  TestObjet(hA);
  hasard hB(10, 5);
  hA.affiche();
  if (hA==hB) {
    cout << "Wouah ça marche" <<endl;
  }
  else {
    cout << "Ils sont différents" <<endl;
  }
  if (! (hB==hB)) {
    cout << "Pas de chance" << endl;
  }
  return 0;
}

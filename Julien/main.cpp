#include<iostream>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include"Classematrice.h"

using namespace std;

int main() {
srand(time(NULL));
Matrice M(3,5);

for (int i=0; i< M.get_NBligne(); i++) {
   for (int j=0; j<M.get_NBcolonne(); j++){
       M.matrice[i][j]= (rand() % 100) +1;
   }
}
M.affiche();

cout<<endl;

//Je teste l'égalité

Matrice N(M.get_NBligne(),M.get_NBcolonne());

cout<<endl;

cout << "Initialisation d'une nouvelle matrice nulle avec les dimensions de la première";
N.affiche();
N=M;
cout << "Egalité avec l'ancienne matrice";
N.affiche();


return 0;
}

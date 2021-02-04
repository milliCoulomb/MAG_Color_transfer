#include<iostream>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include"Classematrice.h"

using namespace std;

int main() {
srand(time(NULL));
Matrice M(3,3);

for (int i=0; i< M.get_NBligne(); i++) {
   for (int j=0; j<M.get_NBcolonne(); j++){
       M.matrice[i][j]= (rand() % 10) +1;
   }
}
cout <<endl;
cout << "Je crée une matrice 3x3 avec des nombres aléatoires compris entre 1 et 10";
M.affiche();

//Je teste l'égalité

Matrice N(M.get_NBligne(),M.get_NBcolonne());

cout<<endl;

cout << "J'initialise une nouvelle matrice nulle avec les dimensions de la première";
N.affiche();
N=M;
cout << "Je fais l'égalité avec l'ancienne matrice";
N.affiche();


//Je teste le produit matriciel

Matrice A = M.produitmatriciel(N);
cout <<endl;
cout << "Je multiplie maintenant les deux matrices 3x3 entre elles";
A.affiche();

//Test autre matrice
Matrice B(3,1);
for (int i=0; i<B.get_NBligne(); i++) {
   for (int j=0; j<B.get_NBcolonne(); j++){
       B.matrice[i][j]= (rand() % 10) +1;
   }
}
cout <<endl;
cout <<endl;
cout << "Autre test de produit de matrice pour pixel"<<endl;
cout <<endl;
cout << "Je crée une matrice colonne 3x1 de nombres aléatoires";
B.affiche();



cout <<endl;

cout << "Je multiplie la matrice 3x3 du debut par cette matrice colonne"<<endl;
Matrice C= M.produitmatriciel(B);

C.affiche();

cout<<endl;

Matrice D(2,1);
for (int i=0; i<D.get_NBligne(); i++) {
   for (int j=0; j<D.get_NBcolonne(); j++){
       D.matrice[i][j]= (rand() % 10) +1;
   }
}
cout <<endl;
cout << "Je crée une matrice colonne 2x1 de nombres aléatoires";
D.affiche();

cout <<endl;

cout << "Je multiplie la matrice 3x3 du debut par cette matrice colonne"<<endl;
cout<<endl;

Matrice E= M.produitmatriciel(D);

E.affiche();

cout <<endl;

return 0;
}

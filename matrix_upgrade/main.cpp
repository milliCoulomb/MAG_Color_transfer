#include<iostream>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include"matrix.h"

using namespace std;

int main() {
srand(time(NULL));
matrix M(3,3);

for (int i=0; i< M.get_NBligne(); i++) {
   for (int j=0; j<M.get_NBcolonne(); j++){
       M.tab[i][j]= (rand() % 10) +1;
   }
}
cout <<endl;
cout << "Je crée une matrix 3x3 avec des nombres aléatoires compris entre 1 et 10";
M.affiche();
matrix Z = M.T();
Z.affiche();
cout << "La matrice transposée." << endl;
//Je teste l'égalité

matrix N(M.get_NBligne(),M.get_NBcolonne());

cout<<endl;

cout << "J'initialise une nouvelle matrix nulle avec les dimensions de la première";
N.affiche();
N=M;
cout << "Je fais l'égalité avec l'ancienne matrix";
N.affiche();


//Je teste le produit matriciel

matrix A = M.prod(N);
cout <<endl;
cout << "Je multiplie maintenant les deux matrixs 3x3 entre elles";
A.affiche();

//Test autre matrix
matrix B(3,1);
for (int i=0; i<B.get_NBligne(); i++) {
   for (int j=0; j<B.get_NBcolonne(); j++){
       B.tab[i][j]= (rand() % 10) +1;
   }
}
cout <<endl;
cout <<endl;
cout << "Autre test de produit de matrix pour pixel"<<endl;
cout <<endl;
cout << "Je crée une matrix colonne 3x1 de nombres aléatoires";
B.affiche();



cout <<endl;

cout << "Je multiplie la matrix 3x3 du debut par cette matrix colonne"<<endl;
matrix C= M.prod(B);

C.affiche();

cout<<endl;

matrix D(2,1);
for (int i=0; i<D.get_NBligne(); i++) {
   for (int j=0; j<D.get_NBcolonne(); j++){
       D.tab[i][j]= (rand() % 10) +1;
   }
}

matrix lms(3,3);
lms.tab[0][0]=0.3811;
lms.tab[0][1]=0.5783;
lms.tab[0][2]=0.0402;
lms.tab[1][0]=0.1967;
lms.tab[1][1]=0.7244;
lms.tab[1][2]=0.0782;
lms.tab[2][0]=0.0241;
lms.tab[2][1]=0.1288;
lms.tab[2][2]=0.8444;
lms.affiche();
matrix pix(3,1);
for (int i=0; i<pix.get_NBligne(); i++) {
   for (int j=0; j<pix.get_NBcolonne(); j++){
       pix.tab[i][j]= (rand() % 10) +1;
   }
}

pix.affiche();
matrix produ = lms.prod(pix);
produ.affiche();


cout <<endl;
cout << "Je crée une matrix colonne 2x1 de nombres aléatoires";
D.affiche();
matrix Y = D.T();
Y.affiche();
cout << "Heu ? Tu t'affiches ?" <<endl;
cout <<endl;

cout << "Je multiplie la matrix 3x3 du debut par cette matrix colonne"<<endl;
cout<<endl;

matrix E= M.prod(D);

E.affiche();

cout <<endl;

return 0;
}

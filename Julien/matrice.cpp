#include<iostream>
#include<ostream>
#include"Classematrice.h"

using namespace std;

double Matrice::get_NBligne() const {
  return NBligne;
}
double Matrice::get_NBcolonne() const {
  return NBcolonne;
}

void Matrice::set_NBligne(int NBligne_) {
  NBligne=NBligne_;
}
void Matrice::set_NBcolonne(int NBcolonne_) {
  NBcolonne=NBcolonne_;
}



//Matrice en mode privée

/*double ** Matrice::get_matrice() const {
  return matrice;
}
void Matrice::set_matrice(double ** matrice_) {
  matrice=matrice_;
}*/



//Constructeur
Matrice::Matrice(const int NBligne_, const int NBcolonne_) :
  NBligne(NBligne_), NBcolonne(NBcolonne_), matrice(new double*[NBligne])
{
  for (int i=0; i<NBligne_; i++) {
    matrice[i]= new double[NBcolonne_];
}
  for (int i=0; i<NBligne_; i++) {
    for (int j=0; j<NBcolonne_; j++) {
      matrice[i][j] =0;}
}
  cout << this <<endl;
}

//Destructeur
Matrice::~Matrice() {
for (int i=0; i<get_NBligne(); i++) delete matrice[i];
delete matrice;
/*cout << "(La matrice a bien été détruite)"<<endl;*/
}



//Affichage
void Matrice::affiche() const {
cout <<endl;
cout << "Représentation de la matrice :"<<endl;
cout <<endl;
for (int i=0; i< get_NBligne(); i++){
   for (int j=0; j< get_NBcolonne(); j++){
     cout << matrice[i][j] << "  ";;
   }
   cout <<endl;
}
cout <<endl;
}


//Egalité
Matrice & Matrice::operator=(const Matrice & matrice_) {

for (int i=0; i< matrice_.get_NBligne(); i++) {
   for (int j=0; j< matrice_.get_NBcolonne(); j++){
       matrice[i][j]= matrice_.matrice[i][j];
   }
}
return *this;
}


//Produit matriciel
Matrice Matrice::produitmatriciel(const Matrice & matrice_){
Matrice M(get_NBligne(),matrice_.get_NBcolonne());

for (int i=0; i< get_NBligne(); i++){
   for (int j=0; j< matrice_.get_NBcolonne(); j++) {
       for (int k=0; k< get_NBcolonne(); k++) {
             M.matrice[i][j]= M.matrice[i][j] + matrice[i][k]*matrice_.matrice[k][j];
       }
   }
}
return M;

}



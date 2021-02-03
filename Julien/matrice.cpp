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


ostream & operator<<(ostream & out, const Matrice & matrice_)
{
  for (int k=0; k< matrice_.get_NBligne(); k++) {
     for (int j=0; j< matrice_.get_NBcolonne(); j++) {
        cout << matrice_[k][j]<<endl;
      }
  cout << endl;
}
  return out;


}

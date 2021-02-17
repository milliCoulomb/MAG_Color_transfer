#include<iostream>
#include<ostream>
#include<time.h>
#include<stdlib.h>
#include"matrix.h"

using namespace std;
double matrix::get_NBligne() const {
  return NBligne;
}
double matrix::get_NBcolonne() const {
  return NBcolonne;
}

void matrix::set_NBligne(int NBligne_) {
  NBligne=NBligne_;
}
void matrix::set_NBcolonne(int NBcolonne_) {
  NBcolonne=NBcolonne_;
}
matrix::matrix(const int NBligne_, const int NBcolonne_) :
  NBligne(NBligne_), NBcolonne(NBcolonne_), tab(new double*[NBligne])
{
  for (int i=0; i<NBligne_; i++) {
    tab[i]= new double[NBcolonne_];
}
  for (int i=0; i<NBligne_; i++) {
    for (int j=0; j<NBcolonne_; j++) {
      tab[i][j] =0;}
}
  //cout << this <<endl;
}

matrix::~matrix() {
for (int i=0; i<get_NBligne(); i++) delete tab[i];
delete tab;
}

void matrix::affiche() const {
cout <<endl;
for (int i=0; i< get_NBligne(); i++){
   for (int j=0; j< get_NBcolonne(); j++){
     cout << tab[i][j] << "  ";;
   }
   cout <<endl;
}
cout <<endl;
}
matrix & matrix::operator=(const matrix & tab_) {

for (int i=0; i< tab_.get_NBligne(); i++) {
   for (int j=0; j< tab_.get_NBcolonne(); j++){
      tab[i][j]= tab_.tab[i][j];
   }
}
return *this;
}
matrix matrix::prod(const matrix & tab_){
  matrix M(get_NBligne(),tab_.get_NBcolonne());
  for (int i=0; i< get_NBligne(); i++){
    for (int j=0; j< tab_.get_NBcolonne(); j++) {
       for (int k=0; k< get_NBcolonne(); k++) {
          M.tab[i][j]= M.tab[i][j] + tab[i][k]*tab_.tab[k][j];
       }
   }
}
return M;
}
matrix matrix::T() const {
  matrix trans(get_NBcolonne(),get_NBligne());
  for (int i=0; i< get_NBligne(); i++){
    for (int j=0; j< get_NBcolonne(); j++){
      trans.tab[i][j]=tab[j][i];
      }
    }
return trans;
}



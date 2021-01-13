#include<iostream>
#include<cstdlib>
#include"classe_hasard.h"
using namespace std;
bool hasard::operator==(const hasard & h_) const
{
  if (Nmax != h_.Nmax) return false;
  for (int i=0; i<Nmax; i++) {
    if (tableau_random[i] != h_.tableau_random[i]) return false;
  }
  return true;
}
bool hasard::operator!=(const hasard & h_) const
{
  return ! (*this == h_);
}
hasard::hasard()
  : Nmax(0), Vmax(0), tableau_random(0)
{
}
hasard::hasard(const int Nmax_, const int Vmax_) :
  Nmax(Nmax_), Vmax(Vmax_), tableau_random(new int[Nmax_])
{
  for (int i=0; i<Nmax; i++) {
    tableau_random[i]=rand()%Vmax;
  }
  cout << this <<endl;
}

hasard::~hasard()
{
  if (tableau_random) {
    delete [] tableau_random;
  }
  cout << this <<endl;
}

/*
int hasard::get_Nmax() const {
  return Nmax;
}
int hasard::get_Vmax() const {
  return Vmax;
}
void hasard::set_Nmax(int Nmax_) {
  Nmax=Nmax_;
}
void hasard::set_Vmax(int Vmax_) {
  Vmax=Vmax_;
}
*/
void hasard::affiche() const
{
  for (int i=0; i<Nmax; i++) {
    cout << "Valeur[" << i << "] = " << tableau_random[i] << endl;
  }
}
void hasard::affiche(const unsigned int i_) const
{
  cout << "valeur[" << i_ << "] = " << tableau_random[i_] << endl;
}

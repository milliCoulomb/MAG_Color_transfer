#ifndef Matrice_
#define Matrice_
#include<iostream>
#include<ostream>

using namespace std :

class matrice {

private :

int NBligne;
int NBcolonne;
double **matrice;

public :

//Constructeur 
matrice(const NBligne, const NBcolonne);

//Destructeur 
~matrice();

// get et set 
double get_NBligne() const;
double get_NBcolonne() const;

void set_NBligne(const int NBligne_);
void set_NBcolonne(const int NBcolonne_);

//Surcharge opérateur
matrice & operator=(const matrice & matrice_);
ostream & operator<<(ostream & out, const matrice & matrice_);

//Produit matriciel 
double produit(matrice matrice_);
}

#include<iostream>
#include<ostream>

using namespace std ;

class Matrice {

private :

int NBligne;
int NBcolonne;

public :

double **matrice;

//Constructeur 
Matrice(const int NBligne_, const int NBcolonne_);

//Destructeur
/*~Matrice();*/

// get et set 
double get_NBligne() const;
double get_NBcolonne() const;

void set_NBligne(const int NBligne_);
void set_NBcolonne(const int NBcolonne_);

//Surcharge opérateur
/*friend Matrice & operator=(const Matrice & matrice_)*/

// Produit matriciel
/*double produitmatriciel(const Matrice & matrice_);*/
};

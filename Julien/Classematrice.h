#include<iostream>
#include<ostream>

using namespace std ;

class Matrice {

private :

int NBligne;
int NBcolonne;
/*double **matrice*/

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



//Matrice en mode privée
/*double** get_matrice() const;
void set_matrice(const double** matrice_);*/



//Affichage
void affiche() const;


//Surcharge opérateur
Matrice & operator=(const Matrice & matrice_);

// Produit matriciel
/*double produitmatriciel(const Matrice & matrice_);*/
};

#include<iostream>
#include<ostream>

using namespace std ;

class Matrice {

private :

int NBligne;
int NBcolonne;
double **matrice;

public :

//Constructeur 
Matrice(const int NBligne_, const int NBcolonne_);

//Destructeur 
~Matrice();

// get et set 
double get_NBligne() const;
double get_NBcolonne() const;

void set_NBligne(const int NBligne_);
void set_NBcolonne(const int NBcolonne_);

//Surcharge opérateur
friend ostream & operator<<(ostream & out, const Matrice & matrice_);

};

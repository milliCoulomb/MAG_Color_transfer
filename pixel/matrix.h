#include<iostream>
#include<ostream>

using namespace std ;

class matrix {

private :

int NBligne;
int NBcolonne;

public :

double **tab;
matrix(const int NBligne_, const int NBcolonne_);
~matrix();
double get_NBligne() const;
double get_NBcolonne() const;
void set_NBligne(const int NBligne_);
void set_NBcolonne(const int NBcolonne_);
void affiche() const;
matrix & operator=(const matrix & matrix_);
matrix prod(const matrix & matrix_);
matrix T() const;
};

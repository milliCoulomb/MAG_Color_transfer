#ifndef _MATRIX_H_
#define _MATRIX_H_
class matrix {
private :
	int NBligne;
	int NBcolonne;
public :

	long double **tab;
	matrix(const int NBligne_, const int NBcolonne_);
	virtual ~matrix();
	double get_NBligne() const;
	double get_NBcolonne() const;
	void set_NBligne(const int NBligne_);
	void set_NBcolonne(const int NBcolonne_);
	void affiche() const;
	matrix & operator=(const matrix & matrix_);
	matrix prod(const matrix & matrix_);
	matrix T() const;
};
#endif //_MATRIX_H_
#include"pixel.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
int pixel::get_lines() const {
  	return lines;
}
int pixel::get_rows() const {
  	return rows;
}
pixel::pixel() :
	matrix(3, 1)
{
	new (this) matrix(3, 1);
}

pixel::~pixel()
{
	//for (int i=0; i<3; i++) delete tab[i];
	//delete tab;
	//cout << "cc" << endl;
}
void pixel::LMS() const {
	matrix inter(get_lines(), get_rows());
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++) {
			inter.tab[i][j]=tab[i][j];
		}
	}
	matrix lms(3,3);
	lms.tab[0][0]=0.3811;
	lms.tab[0][1]=0.5783;
	lms.tab[0][2]=0.0402;
	lms.tab[1][0]=0.1967;
	lms.tab[1][1]=0.7244;
	lms.tab[1][2]=0.0782;
	lms.tab[2][0]=0.0241;
	lms.tab[2][1]=0.1288;
	lms.tab[2][2]=0.8444;
	//lms.affiche();
    matrix Z = lms.prod(inter);
    for (int i=0; i<3; i++) {
		for (int j=0; j<1; j++){
			tab[i][j]=Z.tab[i][j];
		}
	}
}
void pixel::LAB() const {
	matrix inter(get_lines(), get_rows());
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++) {
			inter.tab[i][j]=tab[i][j];
		}
	}
	matrix lab1(3,3);
	lab1.tab[0][0]=1/sqrt(3);
	lab1.tab[1][1]=1/sqrt(6);
	lab1.tab[2][2]=1/sqrt(2);
	//lab1.affiche();
	matrix lab2(3,3);
	lab2.tab[0][0]=1.0;
	lab2.tab[0][1]=1.0;
	lab2.tab[0][2]=1.0;
	lab2.tab[1][0]=1.0;
	lab2.tab[1][1]=1.0;
	lab2.tab[1][2]=-2.0;
	lab2.tab[2][0]=1.0;
	lab2.tab[2][1]=-1.0;
	lab2.tab[2][2]=0.0;
	//lab2.affiche();
	if (tab[0][0]==0 and tab[1][0]==0 and tab[2][0]==0) {
        tab[0][0]=0;
        tab[1][0]=1;
        tab[2][0]=1;
    }
    else {
		for (int i=0; i<get_lines(); i++) {
			for (int j=0; j<get_rows(); j++){
				double a = log(inter.tab[i][j]);
				inter.tab[i][j]=a;
				// Passage en logarithme des couleurs.
			}
		}
		matrix M=lab1.prod(lab2);
	    matrix M3=M.prod(inter);
	    for (int i=0; i<3; i++) {
			for (int j=0; j<1; j++){
				tab[i][j]=M3.tab[i][j];
			}
		}
	}
}
void pixel::back_to_LMS_from_LAB() const{
	matrix inter(get_lines(), get_rows());
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++) {
			inter.tab[i][j]=tab[i][j];
		}
	}
	matrix lab1_inv(3,3);
	lab1_inv.tab[0][0]=1/sqrt(3);
	lab1_inv.tab[1][1]=1/sqrt(6);
	lab1_inv.tab[2][2]=1/sqrt(2);
	matrix lab2_inv(3,3);
	lab2_inv.tab[0][0]=1.0;
	lab2_inv.tab[0][1]=1.0;
	lab2_inv.tab[0][2]=1.0;
	lab2_inv.tab[1][0]=1.0;
	lab2_inv.tab[1][1]=1.0;
	lab2_inv.tab[1][2]=-1.0;
	lab2_inv.tab[2][0]=1.0;
	lab2_inv.tab[2][1]=-2.0;
	lab2_inv.tab[2][2]=0.0;
	matrix M=lab2_inv.prod(lab1_inv);
	matrix M4 = M.prod(inter);
    for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++){
			tab[i][j]=M4.tab[i][j];
		}
	}
}
void pixel::back_to_RGB_from_LMS() const{
	matrix inter(get_lines(), get_rows());
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++) {
			inter.tab[i][j]=tab[i][j];
		}
	}
	matrix lms_inv(3,3);
	lms_inv.tab[0][0]=4.4679;
	lms_inv.tab[0][1]=-3.5873;
	lms_inv.tab[0][2]=0.1193;
	lms_inv.tab[1][0]=-1.2186;
	lms_inv.tab[1][1]=2.3809;
	lms_inv.tab[1][2]=-0.1624;
	lms_inv.tab[2][0]=0.0497;
	lms_inv.tab[2][1]=-0.2439;
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++){
			double b=exp(inter.tab[i][j]);
			inter.tab[i][j]=b;
			//passage en exopnentiel des couleurs, retour vers l'espace RGB.
		}
	}
	matrix M=lms_inv.prod(inter);
    for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++){
			tab[i][j]=M.tab[i][j];
		}
	}
	if (tab[0][0]>255.0) { 
        tab[0][0]=255.0;
    }
    if (tab[1][0]>255.0) { 
        tab[1][0]=255.0;
    }
    if (tab[2][0]>255.0) { 
        tab[2][0]=255.0;
    }
    if (tab[0][0]<0) { 
        tab[0][0]=0;
    }
    if (tab[1][0]<0) { 
        tab[1][0]=0;
    }
    if (tab[2][0]<0) { 
        tab[2][0]=0;
    }

}
double pixel::RLl() const {
	return tab[0][0];
}
double pixel::GMa() const {
	return tab[1][0];
}
double pixel::BSb() const {
	return tab[2][0];
}

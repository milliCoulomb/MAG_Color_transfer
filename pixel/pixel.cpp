#include"pixel.h"
#include"matrix.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
double pixel::get_red() const {
	return p_red;
}
double pixel::get_green() const {
	return p_green;
}
double pixel::get_blue() const {
	return p_blue;
}
void pixel::set_red(const double red_) {
	p_red=red_;
}
void pixel::set_green(const double green_) {
	p_green=green_;
}
void pixel::set_blue(const double blue_) {
	p_blue=blue_;
}
pixel::pixel():
{
	matrix M(lines, rows);
}
pixel::~pixel():
{
	delete M;
}
pixel::pixel LMS() const {
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
	return prod(lms, pixel);
}
pixel::pixel LAB() const {
	matrix lab1(3,3);
	lab1.tab[0][0]=1/pow(3, 0.5);
	lab1.tab[1][1]=1/pow(6, 0.5);
	lab1.tab[2][2]=1/pow(2, 0.5);
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
	for (int i=0; i<lines; i++) {
		for (int j=0; j<rows; j++){
			pixel.tab[i][j]=log(pixel.tab[i][j]);
			// Passage en logarithme des couleurs.
		}
	}
	M2 = prod(lab2, pixel);
	return prod(lab1, M2);
}
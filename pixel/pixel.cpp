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

pixel::pixel(const int lines_, const int rows_) :
	lines(lines_), rows(rows_), matrix(lines, rows)
{
	new (this) matrix(lines, rows);
	cout << this <<endl;
}

pixel::~pixel()
{
	for (int i=0; i<get_lines(); i++) delete tab[i];
	delete tab;
}
pixel pixel::LMS(const pixel & pixel_) {
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
    pixel Z = lms.prod(pixel_);
	return Z;
}
pixel pixel::LAB(const pixel & pixel_) {
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
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++){
			pixel_.tab[i][j]=log(pixel_.tab[i][j]);
			// Passage en logarithme des couleurs.
		}
	}
	pixel M2 = lab2.prod(pixel_);
    pixel M3=lab1.prod(M2);
	return M3;
}
pixel pixel::back_to_LMS_from_LAB() const {
	matrix lab1_inv(3,3);
	lab1_inv.tab[0][0]=1/pow(3, 0.5);
	lab1_inv.tab[1][1]=1/pow(6, 0.5);
	lab1_inv.tab[2][2]=1/pow(2, 0.5);
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
	M3=lab1_inv.prod(pixel);
	return lab2_inv.prod(M3);
}
pixel pixel::back_to_RGB_from_LMS() const {
	matrix lms_inv(3,3);
	lms_inv.tab[0][0]=4.4679;
	lms_inv.tab[0][1]=-3.5873;
	lms_inv.tab[0][2]=0.1193;
	lms_inv.tab[1][0]=-1.2186;
	lms_inv.tab[1][1]=2.3809;
	lms_inv.tab[1][2]=-0.1624;
	lms_inv.tab[2][0]=0.0497;
	lms_inv.tab[2][1]=-0.2439;
	lms_inv.tab[2][2]=1.2045;
	for (int i=0; i<get_lines(); i++) {
		for (int j=0; j<get_rows(); j++){
			pixel.tab[i][j]=exp(pixel.tab[i][j]);
			//passage en exopnentiel des couleurs, retour vers l'espace RGB.
		}
	}
	return lms_inv.prod(pixel);
}

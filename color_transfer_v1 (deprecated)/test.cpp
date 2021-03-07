#include"pixel.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
int main () {
	pixel chose;
	//chose.affiche();
	chose.tab[0][0]=254.0;
	chose.tab[1][0]=44.0;
	chose.tab[2][0]=40.0;
	//cout << "Base RVB" <<endl;
	//chose.affiche();
	chose.LMS();
	//cout << "Base LMS" <<endl;
	chose.affiche();
	chose.LAB();
	//cout << "Base LAB" <<endl;
	//chose.affiche();
	chose.back_to_LMS_from_LAB();
	//cout << "Base LMS" <<endl;
	//chose.affiche();
	//cout << "Base RGB" <<endl;
	chose.back_to_RGB_from_LMS();
	//chose.affiche();
	//cout << "coucou" <<endl;
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
	matrix chose2(3,1);
	for (int i=0; i<3; i++) {
		for (int j=0; j<1; j++) {
			chose2.tab[i][j]=chose.tab[i][j];
		}
	}
	matrix test = lms.prod(chose2);
	test.affiche();
	matrix A(2,2);
	A.tab[0][0]=1;
	A.tab[0][1]=2;
	A.tab[1][0]=3;
	A.tab[1][1]=4;
	A.affiche();
	matrix B(2,2);
	B.tab[0][0]=2;
	B.tab[0][1]=1;
	B.tab[1][0]=1;
	B.tab[1][1]=2;
	B.affiche();
	matrix C = A.prod(B);
	C.affiche();
	matrix D = B.prod(A);
	D.affiche();
	return 0;
}
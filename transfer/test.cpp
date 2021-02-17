#include"pixel.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
int main () {
	pixel chose;
	//chose.affiche();
	chose.tab[0][0]=100;
	chose.tab[1][0]=100;
	chose.tab[2][0]=100;
	cout << "Base RVB" <<endl;
	chose.affiche();
	chose.LMS();
	cout << "Base LMS" <<endl;
	//chose.affiche();
	chose.LAB();
	cout << "Base LAB" <<endl;
	//chose.affiche();
	chose.back_to_LMS_from_LAB();
	cout << "Base LMS" <<endl;
	//chose.affiche();
	cout << "Base RGB" <<endl;
	chose.back_to_RGB_from_LMS();
	chose.affiche();
	//cout << "coucou" <<endl;
	return 0;
}
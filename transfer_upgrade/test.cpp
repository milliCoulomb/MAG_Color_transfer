#include"pixel.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
int main () {
	pixel chose;
	chose.tab[0][0]=100;
	chose.tab[1][0]=200;
	chose.tab[2][0]=300;
	chose.affiche();
	/*cout << "Base RVB" <<endl;
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
	chose.affiche();*/
	cout << chose.RLl() << " " << chose.GMa() << " " << chose.BSb() <<endl;
	pixel chose2;
	chose2.tab[0][0]=100;
	chose2.tab[1][0]=200;
	chose2.tab[2][0]=300;
	return 0;
}
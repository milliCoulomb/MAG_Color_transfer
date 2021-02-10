#include"pixel.h"
#include<iostream>
#include<ostream>
#include<cmath>
using namespace std;
int main () {
	pixel chose;
	chose.affiche();
	chose.tab[0][0]=36;
	chose.affiche();
	//cout << "coucou" <<endl;
	return 0;
}
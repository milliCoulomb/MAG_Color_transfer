#include<iostream>
#include<ostream>
#include"Classematrice.h"

using namespace std;

int main() {

Matrice M(3,3);
M.matrice[0][0]=5;

for (int i=0; i<3; i++){
   for (int j=0; j<3; j++){
     cout << M.matrice[i][j];
   }
   cout <<endl;
}

return 0;
}

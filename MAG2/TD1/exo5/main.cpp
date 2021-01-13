#include<iostream>
using namespace std;
int main() {
  int taille;
  cout << "Combien de valeurs souhaiter vous allouez en mémoire ?";
  cin >> taille;
  double pt_tabular = new double[taille];
  delete[] pt_tabular;
  return 0;
}

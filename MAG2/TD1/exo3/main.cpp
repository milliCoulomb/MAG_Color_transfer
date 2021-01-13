#include<iostream>
using namespace std;
int main() {
  int N;
  N=10;
  int & ref_N = N;
  int * pt_N;
  pt_N = &N;
  cout << N << endl;
  cout << ref_N << endl;
  cout << pt_N << endl;
  return 0;
}

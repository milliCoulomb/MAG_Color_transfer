#include<iostream>
#include"fibonacci.h"
using namespace std;
int main() {
  unsigned short int n=10;
  int N = 100;
  int a;
  int b;
  for (int j=0; j<N; j++) {
    a=rfibonacci(n);
  }
  for (int j=0; j<N; j++) {
    b=fibonacci(n);
  }
  cout << a << endl;
  cout << b << endl;
  return(0);
}

  

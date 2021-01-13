
int fibonacci(unsigned short int n) {
  int f0 = 1;
  int f1 = 1;
  int fn;
  for (int i=2; i<n+1; i++) {
    fn= f1 + f0;
    f0=f1;
    f1=fn;
  }
  return fn;
}
int rfibonacci(unsigned short int n) {
  int f0 = 1;
  int f1 = 1;;
  if (n==0) {
    return f0;
  }
  else if (n==1) {
    return f0;
  }
  else {
    return rfibonacci(n-1) + rfibonacci(n-2);
  }
}
  

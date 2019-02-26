#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int *a = new int[n];
  int *b = new int[m];


  delete [] a;
  delete [] b;
  return 0;
}
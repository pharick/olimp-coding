#include <iostream>
#include <iomanip>
#include <cmath>

double sqrt_binary_search(double a, int n) {
  double l = 0;
  double r = 1001;

  while (r - l > 1e-10) {
    double m = (l + r) / 2;

    if (pow(m, n) < a) {
      l = m;
    } else {
      r = m;
    }
  }

  return l;
}

int main() {
  double a;
  int n;
  std::cin >> a >> n;
  std::cout << std::fixed << std::setprecision(11)
            << sqrt_binary_search(a, n) << std::endl;
  return 0;
}
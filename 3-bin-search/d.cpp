#include <iostream>
#include <iomanip>
#include <cmath>

double binary_search(double c) {
  double l = 0;
  double r = 1000000;

  while (r - l > 1e-10) {
    double m = (l + r) / 2;

    if (m*m + sqrt(m) < c) {
      l = m;
    } else {
      r = m;
    }
  }

  return l;
}

int main() {
  double c;
  std::cin >> c;
  std::cout << std::fixed << std::setprecision(9)
            << binary_search(c) << std::endl;
}
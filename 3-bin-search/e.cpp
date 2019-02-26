#include <iostream>
#include <iomanip>
#include <cmath>

double getDistance(int d, int h1, int h2, int k, double x) {
  double r = sqrt(d * d + (h2 - x) * (h2 - x));
  
  double py;
  if (h2 > r)
    py = h2 - r;
  else
    py = 0;

  if (x - py > k)
    return 1e10;
  else
    return h2 - py;
}

int main() {
  int d, h1, h2, k;
  std::cin >> d >> h1 >> h2 >> k;

  double l = 0, r = h1;
  while (r - l > 1e-10) {
    double m = (l + r) / 2;
    if (getDistance(d, h1, h2, k, m) >= 1e10)
      r = m;
    else
      l = m;
  }

  std::cout << std::fixed << std::setprecision(10)
            << getDistance(d, h1, h2, k, l) + h1 << std::endl;

  return 0;
}
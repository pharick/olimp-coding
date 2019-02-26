#include <iostream>

long getOneManBalloonCount(long t, long t_one, long z, long y) {
  long count = 0;

  while (t > 0) {
    if (count % z == 0 && count != 0) t -= y;
    
    t -= t_one;
    if (t >= 0) count++;
  }

  return count;
}

long getBalloonCount(long t, long n, long people[20][4]) {
  long count = 0, one_count;

  for (long i = 0; i < n; i++) {
    one_count = getOneManBalloonCount(t, people[i][0], people[i][1], people[i][2]);
    count += one_count;
    people[i][3] = one_count;
  }

  return count;
}

long binary_search(long m, long n, long people[20][4]) {
  long l = -1;
  long r = 20001;

  while (r - l > 1) {
    long t = (l + r) / 2;

    long balloons = getBalloonCount(t, n, people);
    
    // std::cout << l << " " << r << " " << t << " " << balloons << std::endl;

    if (balloons < m) {
      l = t;
    } else {
      r = t;
    }
  }

  getBalloonCount(r, n, people);
  return r;
}

int main() {
  long m, n;
  long people[20][4] = {};

  std::cin >> m >> n;

  for (long i = 0; i < n; i++) {
    std::cin >> people[i][0] >> people[i][1] >> people[i][2];
  }

  std::cout << binary_search(m, n, people) << std::endl;

  // std::cout << getBalloonCount(2, n, people) << std::endl;

  for (long i = 0; i < n; i++) {
    std::cout << people[i][3];
    if (i < n) std::cout << " ";
  }
  std::cout << std::endl;

  return 0;
}
#include <iostream>

int countCows(int min, int n, int stalls[10000]) {
  int count = 1, last = 0;

  for (int i = 1; i < n;) {
    // std::cout << stalls[i] << " " << stalls[last] << std::endl;
    if (stalls[i] - stalls[last] >= min) {
      count++;
      last = i;
    }
    i++;
  }

  return count;
}

int binary_search(int n, int k, int stalls[10000]) {
  int l = -1;
  int r = stalls[n - 1] - stalls[0] + 1;

  while (r - l > 1) {
    int mid = (l + r) / 2;

    int answ = countCows(mid, n, stalls);
    // std::cout << r << " " << l << " " << mid << " " << answ << std::endl;
    
    if (answ >= k) {
      l = mid;
    } else if (answ < k) {
      r = mid;
    }
  }

  return l;
}

int main() {
  int n, k;
  std::cin >> n >> k;

  int stalls[10000] = {};
  for (int i = 0; i < n; i++) {
    std::cin >> stalls[i];
  }

  std::cout << binary_search(n, k, stalls) << std::endl;

  // for (int i = -1; i <= stalls[n - 1] - stalls[0] + 1; i++) {
  //   std::cout << i << " " << countCows(i, n, stalls) << std::endl;
  // }
  return 0;
}
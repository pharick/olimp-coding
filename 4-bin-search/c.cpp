#include <iostream>

int countRopes(int l, int n, int ropes[100001]) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    count += ropes[i] / l;
  }

  return count;
}

int binary_search(int k, int n, int ropes[100001]) {
  int l = 1;
  int r = 100001;

  while (r - l > 1) {
    int mid = (l + r) / 2;

    int answ = countRopes(mid, n, ropes);
    
    if (answ >= k) {
      l = mid;
    } else if (answ < k) {
      r = mid;
    }
  }

  if (countRopes(l, n, ropes) == k) return l;
  else return 0;
}

int main() {
  int n, k, ropes[100001];
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) std::cin >> ropes[i];

  // std::cout << binary_search(k, n, ropes) << std::endl;

  for (int i = -1; i <= 100; i++) {
    std::cout << i << " " << countRopes(i, n, ropes) << std::endl;
  }

  return 0;
}
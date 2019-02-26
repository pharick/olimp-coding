#include <iostream>

void read_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

int binary_search_first(int *arr, int n, int a) {
  int l = -1;
  int r = n;

  while (r - l > 1) {
    int m = (l + r) / 2;

    if (arr[m] < a) {
      l = m;
    } else {
      r = m;
    }
  }

  if (r < n && arr[r] == a) {
    return r;
  } else {
    return -1;
  }
}

int binary_search_last(int *arr, int n, int a) {
  int l = -1;
  int r = n;

  while (r - l > 1) {
    int m = (l + r) / 2;

    if (arr[m] <= a) {
      l = m;
    } else {
      r = m;
    }
  }

  if (l > -1 && arr[l] == a) {
    return l;
  } else {
    return -1;
  }
}

int main() {
  int n, k, n_arr[100000], k_arr[100000];
  std::cin >> n;
  read_array(n_arr, n);
  std::cin >> k;
  read_array(k_arr, k);

  for (int i = 0; i < k; i++) {
    int first = binary_search_first(n_arr, n, k_arr[i]);
    if (first >= 0) {
      int last = binary_search_last(n_arr, n, k_arr[i]);
      std::cout << last - first + 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }

  return 0;
}
#include <iostream>

void read_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

void print_array(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool binary_search(int *arr, int n, int a) {
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
    return true;
  } else {
    return false;
  }
}

int main() {
  int n, k, n_arr[100000], k_arr[100000];
  std::cin >> n >> k;
  read_array(n_arr, n);
  read_array(k_arr, k);

  for (int i = 0; i < k; i++) {
    std::cout << (binary_search(n_arr, n, k_arr[i]) ? "YES" : "NO") << std::endl;
  }

  return 0;
}
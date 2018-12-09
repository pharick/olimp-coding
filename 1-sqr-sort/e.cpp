#include <iostream>

void fill_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void unsort_array(int arr[], int n, int k) {
  for (int j = 0; j < n; j++) {
    for (int i = n - 1; i > 0; i--) {
      if (k == 0) return;
      if (arr[i] > arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
        k--;
      }
    }
  }
}

int main() {
  int n, k, arr[100];
  std::cin >> n >> k;
  fill_array(arr, n);
  unsort_array(arr, n, k);
  print_array(arr, n);
  return 0;
}
#include <iostream>

void read_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

void read_candies(int candies[][2], int m) {
  for (int i = 0; i < m; i++) {
    std::cin >> candies[i][0];
    std::cin >> candies[i][1];
  }
}

bool is_candy(int a, int b, int candies[][2], int m) {
  for (int i = 0; i < m; i++) {
    if (a == candies[i][0] && b == candies[i][1] || b == candies[i][0] && a == candies[i][1]) {
      return true;
    }
  }
  return false;
}

void candy_sort(int arr[], int n, int candies[][2], int m) {
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1] && !is_candy(arr[i], arr[i + 1], candies, m)) {
        std::swap(arr[i], arr[i + 1]);
      }
    }
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int n, arr[100], m, candies[50][2];
  std::cin >> n;
  read_array(arr, n);
  std::cin >> m;
  read_candies(candies, m);
  candy_sort(arr, n, candies, m);
  print_array(arr, n);
  return 0;
}
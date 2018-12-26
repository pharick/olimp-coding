#include <iostream>

void read_array(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

void make_array(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
}

void quick_sort_two(int arr[], int arr2[], int l, int r)
{
  if (r - l <= 1)
    return;

  int mid = arr[l + rand() % (r - l)];
  int x = l;
  int y = l;

  for (int i = l; i < r; i++)
  {
    if (arr[i] < mid)
    {
      std::swap(arr[x], arr[i]);
      std::swap(arr2[x], arr2[i]);
      if (x != y)
      {
        std::swap(arr[y], arr[i]);
        std::swap(arr2[y], arr2[i]);
      }
      x++;
      y++;
    }
    else if (arr[i] == mid)
    {
      std::swap(arr[y], arr[i]);
      std::swap(arr2[y], arr2[i]);
      y++;
    }
  }

  quick_sort_two(arr, arr2, l, x);
  quick_sort_two(arr, arr2, y, r);
}

int main()
{
  int n, numbers[100000], kilometers[100000];
  std::cin >> n;
  read_array(kilometers, n);
  make_array(numbers, n);
  quick_sort_two(kilometers, numbers, 0, n);

  int min_dist = kilometers[1] - kilometers[0];
  int to_cut = 2;

  for (int i = 2; i < n; i++)
  {
    if (kilometers[i] - kilometers[i - 1] < min_dist)
    {
      min_dist = kilometers[i] - kilometers[i - 1];
      to_cut = i + 1;
    }
  }

  std::cout << numbers[to_cut - 1] << std::endl;

  return 0;
}
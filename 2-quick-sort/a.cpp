#include <iostream>

void read_array(int arr[100], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

void print_array(int arr[100], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void quick_sort(int arr[], int l, int r)
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
      if (x != y)
        std::swap(arr[y], arr[i]);
      x++;
      y++;
    }
    else if (arr[i] == mid)
    {
      std::swap(arr[y], arr[i]);
      y++;
    }
  }

  quick_sort(arr, l, x);
  quick_sort(arr, y, r);
}

int main()
{
  int n, arr[100000];
  std::cin >> n;

  read_array(arr, n);
  quick_sort(arr, 0, n);
  print_array(arr, n);

  return 0;
}
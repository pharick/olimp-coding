#include <iostream>

void print_array(unsigned int arr[100], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

unsigned int make_ith_element(int i)
{
  unsigned int ai = 131 * i * i * i + 77 * i * i + 1345 * i + 1577;
  return ai;
}

void fill_array(unsigned int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    arr[i] = make_ith_element(i + 1);
  }
}

unsigned int find_kth_element(unsigned int arr[], int l, int r, int k)
{
  if (r - l <= 1)
    return arr[l];

  unsigned int mid = arr[l + rand() % (r - l)];
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

  if (k < x)
    return find_kth_element(arr, l, x, k);
  if (k >= y)
    return find_kth_element(arr, y, r, k);
  return mid;
}

int main()
{
  int n, k;
  unsigned int *arr = new unsigned int[10000000];
  std::cin >> n >> k;

  fill_array(arr, n);
  std::cout << find_kth_element(arr, 0, n, k - 1) << std::endl;

  delete[] arr;
  return 0;
}
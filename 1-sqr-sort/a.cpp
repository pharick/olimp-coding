#include <iostream>

void read_array(short arr[100], short n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

void print_array(short arr[100], short n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  short n, arr[100];

  std::cin >> n;
  read_array(arr, n);

  for (short i = 1; i < n; i++)
  {
    if (arr[i] < arr[i - 1])
    {
      for (short j = i; j > 0 && arr[j - 1] > arr[j]; j--)
      {
        std::swap(arr[j - 1], arr[j]);
      }

      print_array(arr, n);
    }
  }

  return 0;
}
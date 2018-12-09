#include <iostream>

void read_array(short arr[], short n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

void sort_array_reverse_insert(short arr[], short n)
{
  for (short i = 1; i < n; i++)
  {
    if (arr[i] > arr[i - 1])
    {
      for (short j = i; j > 0 && arr[j - 1] < arr[j]; j--)
      {
        std::swap(arr[j - 1], arr[j]);
      }
    }
  }
}

int main()
{
  short n, prices[1000];
  std::cin >> n;
  read_array(prices, n);

  sort_array_reverse_insert(prices, n);

  int sum = 0;
  for (short i = 0; i < n; i++)
  {
    if ((i + 1) % 3 != 0)
    {
      sum += prices[i];
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
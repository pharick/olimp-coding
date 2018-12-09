#include <iostream>

void read_array(short arr[], short n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

void sort_array_insert(short arr[], short n)
{
  for (short i = 1; i < n; i++)
  {
    if (arr[i] < arr[i - 1])
    {
      for (short j = i; j > 0 && arr[j - 1] > arr[j]; j--)
      {
        std::swap(arr[j - 1], arr[j]);
      }
    }
  }
}

int main()
{
  short leg, pairs, shoes[1000];
  std::cin >> leg >> pairs;

  read_array(shoes, pairs);
  sort_array_insert(shoes, pairs);

  short count = shoes[pairs - 1] >= leg ? 1 : 0;
  short lastShoe = shoes[pairs - 1];

  for (short i = pairs - 2; i >= 0; i--)
  {
    if (shoes[i] < leg)
      break;

    if (lastShoe - shoes[i] >= 3)
    {
      count++;
      lastShoe = shoes[i];
    }
  }

  std::cout << count << std::endl;
  return 0;
}
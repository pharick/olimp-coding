#include <iostream>

void read_results(int arr[][2], short n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i][0] >> arr[i][1];
  }
}

void sort_results(int arr[][2], short n)
{
  for (short j = 0; j < n; j++)
  {
    for (short i = 0; i < n - 1; i++)
    {
      if (arr[i][1] < arr[i + 1][1] || (arr[i][1] == arr[i + 1][1] && arr[i][0] > arr[i + 1][0]))
      {
        std::swap(arr[i], arr[i + 1]);
      }
    }
  }
}

void print_results(int arr[][2], short n)
{
  for (short i = 0; i < n; i++)
  {
    std::cout << arr[i][0] << " " << arr[i][1] << std::endl;
  }
}

int main()
{
  short n;
  int results[1000][2];
  std::cin >> n;
  read_results(results, n);
  sort_results(results, n);
  print_results(results, n);
  return 0;
}
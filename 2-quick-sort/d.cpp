#include <iostream>
#include <iomanip>
#include <algorithm>

void read_array(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }
}

int main()
{
  int n, grooms[100000] = {};
  double capital;
  std::cin >> n;
  read_array(grooms, n);
  std::cin >> capital;

  std::sort(grooms, grooms + n);

  for (int i = 0; i < n; i++)
  {
    double new_capital = (capital * 1.0 + grooms[i]) / 2;

    if (new_capital > capital)
      capital = new_capital;
  }

  std::cout << std::fixed << std::setprecision(6)
            << capital << std::endl;

  return 0;
}
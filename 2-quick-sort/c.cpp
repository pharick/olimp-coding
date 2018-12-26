#include <iostream>

void read_tasks(int tasks[][2], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cin >> tasks[i][0] >> tasks[i][1];
  }
}

void sort_tasks(int arr[][2], int l, int r)
{
  if (r - l <= 1)
    return;

  int mid = arr[l + rand() % (r - l)][0];
  int x = l;
  int y = l;

  for (int i = l; i < r; i++)
  {
    if (arr[i][0] < mid)
    {
      std::swap(arr[x], arr[i]);
      if (x != y)
        std::swap(arr[y], arr[i]);
      x++;
      y++;
    }
    else if (arr[i][0] == mid)
    {
      std::swap(arr[y], arr[i]);
      y++;
    }
  }

  sort_tasks(arr, l, x);
  sort_tasks(arr, y, r);
}

int main()
{
  int n, tasks[100000][2] = {};
  long skill;
  std::cin >> n >> skill;

  read_tasks(tasks, n);
  sort_tasks(tasks, 0, n);

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (tasks[i][0] > skill)
      break;

    count++;
    skill += tasks[i][1];
  }

  std::cout << count << std::endl;
  return 0;
}
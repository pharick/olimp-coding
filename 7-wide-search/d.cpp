#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Square {
  int x, y;
};

int n, m;
int heights[100][100];
std::vector<Square> topsort;
short colors[100][100];

void dfs_1(int x, int y) {
  colors[x][y] = GRAY;

  if (x - 1 >= 0 && heights[x - 1][y] <= heights[x][y] && !colors[x - 1][y]) dfs_1(x - 1, y);
  if (x + 1 < n && heights[x + 1][y] <= heights[x][y] && !colors[x + 1][y]) dfs_1(x + 1, y);
  if (y - 1 >= 0 && heights[x][y - 1] <= heights[x][y] && !colors[x][y - 1]) dfs_1(x, y - 1);
  if (y + 1 < m && heights[x][y + 1] <= heights[x][y] && !colors[x][y + 1]) dfs_1(x, y + 1);

  colors[x][y] = BLACK;
  topsort.push_back({x, y});
}

void dfs_2(int x, int y) {
  colors[x][y] = GRAY;

  if (x - 1 >= 0 && heights[x - 1][y] >= heights[x][y] && !colors[x - 1][y]) dfs_2(x - 1, y);
  if (x + 1 < n && heights[x + 1][y] >= heights[x][y] && !colors[x + 1][y]) dfs_2(x + 1, y);
  if (y - 1 >= 0 && heights[x][y - 1] >= heights[x][y] && !colors[x][y - 1]) dfs_2(x, y - 1);
  if (y + 1 < m && heights[x][y + 1] >= heights[x][y] && !colors[x][y + 1]) dfs_2(x, y + 1);

  colors[x][y] = BLACK;
}

int main() {
  std::cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      std::cin >> heights[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!colors[i][j]) dfs_1(i, j);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      colors[i][j] = WHITE;

  int count = 0;
  for (int i = 0; i < topsort.size(); i++) {
    if (!colors[topsort[i].x][topsort[i].y]) {
      count++;
      dfs_2(topsort[i].x, topsort[i].y);
    }

    // for (int k = 0; k < n; k++) {
    //   for (int j = 0; j < m; j++)
    //     std::cout << colors[k][j] << " ";
    //   std::cout << std::endl;
    // }
    // std::cout << "-----" << std::endl;
  }

  std::cout << count << std::endl;
  return 0;
}
#include <iostream>

int n, m;
char area[200][200];
bool visited[200][200];

void dfs(int i, int j) {
  if (visited[i][j]) return;

  visited[i][j] = true;

  if (i > 0 && area[i - 1][j] == '#') dfs(i - 1, j);
  if (i < n - 1 && area[i + 1][j] == '#') dfs(i + 1, j);
  if (j > 0 && area[i][j - 1] == '#') dfs(i, j - 1);
  if (j < m - 1 && area[i][j + 1] == '#') dfs(i, j + 1);
}

int main() {
  std::cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> area[i][j];
    }
  }

  int components = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (area[i][j] == '#' && !visited[i][j]) {
        components++;
        dfs(i, j);
      }
    }
    std::cout << std::endl;
  }

  std::cout << components << std::endl;
  return 0;
}
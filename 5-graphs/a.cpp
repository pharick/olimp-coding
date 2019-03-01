#include <iostream>
#include <vector>

std::vector<int> g[100];
bool visited[100] = {false};

void dfs(int v) {
  visited[v] = true;

  for (int u: g[v])
    if (!visited[u]) {
      dfs(u);
    }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  int components = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) components++;
    dfs(i);
  }

  std::cout << components << std::endl;

  return 0;
}
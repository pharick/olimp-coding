#include <iostream>
#include <vector>

std::vector<int> g[100000];
bool visited[100000] = {false};

void dfs(int v) {
  visited[v] = true;

  for (int u: g[v])
    if (!visited[u]) {
      dfs(u);
    }
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    k--;

    g[k].push_back(i);
    g[i].push_back(k);
  }

  int components = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      components++;
      dfs(i);
    }
  }

  std::cout << components << std::endl;

  return 0;
}
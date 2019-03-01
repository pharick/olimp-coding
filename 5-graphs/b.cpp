#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

std::vector<int> g[100];
short color[100] = {WHITE};
int parents[100] = {};
bool cycle = false;

void dfs(int v) {
  color[v] = GRAY;

  for (int u: g[v]) {
    if (!color[u]) {
      parents[u] = v;
      dfs(u);
    }

    if (parents[v] != u && color[u] == GRAY) {
      cycle = true;
      return;
    }
  }

  color[v] = BLACK;
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool connection;
      std::cin >> connection;
      if (connection) g[i].push_back(j);
    }
  }

  dfs(0);

  if (cycle) {
    std::cout << "NO";
  } else {
    bool all_visited = true;

    for (int i = 0; i < n; i++)
      if (!color[i]) {
        all_visited = false;
        break;
      }

    std::cout << (all_visited ? "YES" : "NO");
  }

  std::cout << std::endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> g[100];
std::queue<int> queue;
int dist[100];
bool visited[100];

void bfs(int v) {
  queue.push(v);
  visited[v] = true;
  dist[v] = 0;

  while (queue.size() > 0) {
    int x = queue.front();
    queue.pop();

    for (int i : g[x]) {
      if (!visited[i]) {
        queue.push(i);
        visited[i] = true;
        dist[i] = dist[x] + 1;
      }
    }
  }
}

int main() {
  for (int i = 0; i < 100; i++) dist[i] = -1;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool r;
      std::cin >> r;
      if (r) g[i].push_back(j);
    }
  }

  int from, to;
  std::cin >> from >> to;

  if (from == to) {
    std::cout << 0 << std::endl;
    return 0;
  } else {
    bfs(from - 1);
    std::cout << dist[to - 1] << std::endl;
  }

  return 0;
}
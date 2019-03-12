#include <iostream>
#include <vector>
#include <queue>

std::vector<int> g[100];
std::vector<int> path[100];
std::queue<int> queue;
int dist[100];
bool visited[100];

void bfs(int v) {
  queue.push(v);
  visited[v] = true;
  dist[v] = 0;
  path[v].push_back(v);

  while (queue.size() > 0) {
    int x = queue.front();
    queue.pop();

    for (int i : g[x]) {
      if (!visited[i]) {
        queue.push(i);
        visited[i] = true;
        dist[i] = dist[x] + 1;
        
        for (int l = 0; l < path[x].size(); l++) path[i].push_back(path[x][l]);
        path[i].push_back(i);
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
      if (r) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
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
    
    for (int i = 0; i < path[to - 1].size(); i++) std::cout << path[to - 1][i] + 1 << " ";
    std::cout << std::endl;
  }

  return 0;
}
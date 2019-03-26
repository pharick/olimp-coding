#include <iostream>
#include <vector>

#define INF 10000000

struct Edge {
  int to;
  int len;
};

int n, m;
std::vector<Edge> g[100];
int d[100];
bool visited[100];

void init(int v) {
  for (int i = 0; i < n; i++) {
    d[i] = INF;
    visited[i] = false;
  }
  d[v] = 0;
}

void relax(int x) {
  for (Edge &e : g[x]) {
    if (d[e.to] > d[x] + e.len) {
      d[e.to] = d[x] + e.len;
    }
  }
}

int find_min() {
  int x = -1;
  int dist = INF;
  for (int i = 0; i < n; i++) {
    if (d[i] < dist && !visited[i]) {
      x = i;
      dist = d[i];
    }
  }
  return x;
}

void dijkstra(int v) {
  init(v);
  int x;
  while((x = find_min()) != -1) {
    visited[x] = true;
    relax(x);
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, dist;
    std::cin >> from >> to >> dist;
    g[from - 1].push_back({to - 1, dist});
    g[to - 1].push_back({from - 1, dist});
  }

  long min = INF * n;
  int min_n = 0;
  for (int i = 0; i < n; i++) {
    dijkstra(i);
    long max = 0;
    for (int j = 0; j < n; j++) {
      if (d[j] > max) {
        max = d[j];
      }
    }

    if (max < min) {
      min = max;
      min_n = i;
    }
  }

  std::cout << min_n + 1 << std::endl;

  return 0;
}
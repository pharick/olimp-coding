#include <iostream>
#include <vector>

#define INF 1000000000

struct Edge {
  int to;
  int len;
};

int n, s, f;
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
  std::cin >> n >> s >> f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist;
      std::cin >> dist;
      if (dist > 0) {
        g[i].push_back({j, dist});
      }
    }
  }

  dijkstra(s - 1);
  std::cout << (d[f - 1] == INF ? -1 : d[f - 1]) << std::endl;

  return 0;
}
#include <iostream>
#include <vector>

#define INF 100000

struct Edge {
  int to;
  int len;
};

int n;
std::vector<Edge> g[100];
int d[100];
int parents[100];
int cycle_from = -1;

void init(int v) {
  for (int i = 0; i < n; i++) {
    d[i] = INF;
  }
  d[v] = 0;
}

bool relax(int x) {
  bool success = false;
  for (Edge &e : g[x]) {
    if (d[e.to] > d[x] + e.len) {
      d[e.to] = d[x] + e.len;
      parents[e.to] = x;
      success = true;
    }
  }
  return success;
}

void bellman_ford(int v) {
  init(v);
  for (int i = 0; i < n - 1; i++) {
    for (int x = 0; x < n; x++) {
      relax(x);
    }
  }

  for (int x = 0; x < n; x++) {
    if (relax(x)) {
      cycle_from = x;
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist;
      std::cin >> dist;
      if (i == j) continue;
      g[i].push_back({j, dist});
    }
  }

  bellman_ford(0);

  if (cycle_from != -1) {
    std::cout << "YES" << std::endl;

    // std::cout << cycle_from << std::endl;

    std::vector<int> cycle;
    cycle.push_back(cycle_from);
    
    while (parents[cycle.back()] != cycle_from) {
      cycle.push_back(parents[cycle.back()]);
    }

    std::cout << cycle.size() << std::endl;

    for (int v : cycle) {
      std::cout << v + 1 << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
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
bool cycle_from = -1;
int cycle_len = 0;
std::vector << 

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
    std::cout << "YES" << std::endl
              << cycle_from << std::endl;
    int from = cycle_from;
    do {
      std::cout << from + 1 << " ";
      from = parents[from];
    } while (from != cycle_from);
    std::cout << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
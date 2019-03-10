#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

std::vector<int> g[100000];
std::vector<int> topsort;
unsigned long times[100000];
short colors[100000];

void dfs(int v) {
  colors[v] = GRAY;

  for (int u: g[v]) {
    if (!colors[u]) {
      dfs(u);
    }
  }

  colors[v] = BLACK;
  topsort.push_back(v);
}

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) std::cin >> times[i];

  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;

    for (int j = 0; j < k; j++) {
      int r;
      std::cin >> r;
      r--;
      g[i].push_back(r);
    }
  }

  for (int i = 0; i < n; i++)
    if (colors[i] == WHITE) dfs(i);

  unsigned long sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    sum += times[topsort[i]];
    count++;

    if (topsort[i] == 0) break;
  }


  std::cout << sum << " " << count << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << topsort[i] + 1 << " ";
    if (topsort[i] == 0) break;
  }

  std::cout << std::endl;
  return 0;
}
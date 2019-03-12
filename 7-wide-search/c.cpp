#include <iostream>
#include <vector>
#include <queue>

int n;
std::vector<int> path[20][20];
std::queue<int> queue;
int dist[20][20];
bool visited[20][20];

void bfs(int x, int y) {
  queue.push(x);
  queue.push(y);
  visited[x][y] = true;
  dist[x][y] = 0;
  path[x][y].push_back(x);
  path[x][y].push_back(y);

  while (queue.size() > 0) {
    int cx = queue.front();
    queue.pop();
    int cy = queue.front();
    queue.pop();

    for (int dx : {-2, -1, 1, 2})
      for (int dy : {-2, -1, 1, 2})
        if (abs(dx) != abs(dy))
          if (cx + dx >= 0 && cx + dx < n && cy + dy >= 0 && cy + dy < n && !visited[cx + dx][cy + dy]) {
            queue.push(cx + dx);
            queue.push(cy + dy);
            visited[cx + dx][cy + dy] = true;
            dist[cx + dx][cy + dy] = dist[cx][cy] + 1;
            
            for (int l = 0; l < path[cx][cy].size(); l++) path[cx + dx][cy + dy].push_back(path[cx][cy][l]);
            path[cx + dx][cy + dy].push_back(cx + dx);
            path[cx + dx][cy + dy].push_back(cy + dy);
          }
  }
}

int main() {
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      dist[i][j] = -1;

  std::cin >> n;

  int from[2], to[2];
  std::cin >> from[0] >> from[1] >> to[0] >> to[1];
  from[0]--, from[1]--, to[0]--, to[1]--;

  if (from[0] == to[0] && from[1] == to[1]) {
    std::cout << 0 << std::endl;
    return 0;
  } else {
    bfs(from[0], from[1]);
    std::cout << dist[to[0]][to[1]] << std::endl;
    
    for (int i = 0; i < path[to[0]][to[1]].size(); i++) std::cout << path[to[0]][to[1]][i] + 1 << " ";
    std::cout << std::endl;
  }

  return 0;
}
#include <iostream>
#include <cstring>
#include <vector>

#define INF 1000000

struct Edge {
    int x, y, len;
};

int n, m, start_x, start_y, finish_x, finish_y;
char field[50][50];
std::vector<Edge> g[50][50];
bool visited[50][50];
int d[50][50];

void make_graph(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;

    if (field[x - 1][y] != '#') {
        g[x][y].push_back({x - 1, y, 1});
        make_graph(x - 1, y);
    }

    if (field[x][y - 1] != '#') {
        g[x][y].push_back({x, y - 1, 1});
        make_graph(x, y - 1);
    }

    if (field[x + 1][y] != '#') {
        g[x][y].push_back({x + 1, y, 1});
        make_graph(x + 1, y);
    }

    if (field[x][y + 1] != '#') {
        g[x][y].push_back({x, y + 1, 1});
        make_graph(x, y + 1);
    }

    int l, t, r, b,
        ld = 0, td = 0, rd = 0, bd = 0,
        mind;

    for (int i = x; i >= 0; i--) {
        td++;
        if (field[i - 1][y] == '#') {
            t = i;
            mind = td;
            break;
        }
    }

    for (int i = y; i >= 0; i--) {
        ld++;
        if (field[x][i - 1] == '#') {
            l = i;
            if (ld < mind) mind = ld;
            break;
        }
    }

    for (int i = x; i < n; i++) {
        bd++;
        if (field[i + 1][y] == '#') {
            b = i;
            if (bd < mind) mind = bd;
            break;
        }
    }

    for (int i = y; i < m; i++) {
        rd++;
        if (field[x][i + 1] == '#') {
            r = i;
            if (rd < mind) mind = rd;
            break;
        }
    }

    if (mind == ld) {
        g[x][y].push_back({t, y, mind});
        make_graph(t, y);
        g[x][y].push_back({x, r, mind});
        make_graph(x, r);
        g[x][y].push_back({b, y, mind});
        make_graph(b, y);
    } else if (mind == td) {
        g[x][y].push_back({x, l, mind});
        make_graph(x, l);
        g[x][y].push_back({x, r, mind});
        make_graph(x, r);
        g[x][y].push_back({b, y, mind});
        make_graph(b, y);
    } else if (mind == rd) {
        g[x][y].push_back({x, l, mind});
        make_graph(x, l);
        g[x][y].push_back({t, y, mind});
        make_graph(t, y);
        g[x][y].push_back({b, y, mind});
        make_graph(b, y);
    } else if (mind == bd) {
        g[x][y].push_back({x, l, mind});
        make_graph(x, l);
        g[x][y].push_back({t, y, mind});
        make_graph(t, y);
        g[x][y].push_back({x, r, mind});
        make_graph(x, r);
    };
}

void init(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = INF;
        }
    }
    d[x][y] = 0;
}

void relax(int x, int y) {
    for (Edge &e : g[x][y]) {
        if (d[e.x][e.y] > d[x][y] + e.len) {
            d[e.x][e.y] = d[x][y] + e.len;
        }
    }
}

void bellman_ford(int x, int y) {
    init(x, y);
    for (int k = 0; k < n * m - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                relax(i, j);
            }
        }
    }
}

int main() {
    std::cin >> n >> m;

    // Считываем поле
    for (int i = 0; i < n; i++) {
        std::cin >> field[i];
    }

    // Находим точки старта и финиша
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }

            if (field[i][j] == 'T') {
                finish_x = i;
                finish_y = j;
            }
        }
    }

    make_graph(start_x, start_y);
    bellman_ford(start_x, start_y);

    std::cout << d[finish_x][finish_y] << std::endl;
    return 0;
}
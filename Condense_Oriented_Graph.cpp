#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<vector<int>> g, grev;
vector<int> used;
vector<int> order;

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i]);
    order.push_back(v);
}

void dfs_rev(int v, int color) {
    if (used[v]) return;
    used[v] = color;
    for (int i = 0; i < grev[v].size(); i++)
        dfs_rev(grev[v][i], color);
}


int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    grev.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        grev[y].push_back(x);
    }
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    used.assign(n, 0);
    int color = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (!used[order[i]])
            dfs_rev(order[i], color++);
    }
    unordered_set<pair<int, int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
            if (used[i] != used[g[i][j]])
                edges.insert({ used[i], used[g[i][j]] });
    cout << edges.size();
}

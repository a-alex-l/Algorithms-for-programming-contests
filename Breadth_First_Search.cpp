#include<iostream>
#include<vector>
#include<cmath>
#include <queue>

using namespace std;

vector<vector<int>> g;

void bfs(vector<int> &color, int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            if (color[g[v][i]] == -1) {
                color[g[v][i]] = color[v] + 1;
                q.push(g[v][i]);
            }
        }
    }
}

int main() {
    int n, s, m;
    cin >> n >> s >> m;
    s--;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
    }
    vector<int> ans(n, -1);
    ans[s] = 0;
    bfs(ans, s);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

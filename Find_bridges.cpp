#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> g, numbs;
vector<int> tin, up, answer;
int time = 1;
vector<pair<int, int>> bridges;

int dfs(int v, int p, int j) {
    if (tin[v] != 0) return tin[v];
    tin[v] = up[v] = time++;
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            int ans = dfs(g[v][i], v, i);
            up[v] = min(up[v], ans);
        }
    }
    if (tin[v] == up[v] && p != -1) {
        bridges.push_back({ v, p });
        answer.push_back(numbs[p][j]);
    }
    return up[v];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    numbs.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        numbs[x].push_back(i + 1);
        numbs[y].push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
        if (tin[i] == 0)
            dfs(i, -1, -1);
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "\n";
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<vector<int>> g;
int n, m;

vector<int> tin, up, answer;
int time = 1;

void find_cut_vertex(int v, int p) {
    if (tin[v] != 0) return;
    tin[v] = up[v] = time++;
    int children = 0;
    for (int i = 0; i < g[v].size(); i++) {
        if (g[v][i] != p) {
            if (tin[g[v][i]])
                up[v] = min(tin[g[v][i]], up[v]);
            else {
                find_cut_vertex(g[v][i], v);
                children++;
                up[v] = min(up[v], up[g[v][i]]);
                if (p != -1 && up[g[v][i]] >= tin[v])
                    answer[v] = 1;
            }
        }
    }
    if (children > 1 && p == -1)
        answer[v] = 1;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int count = 0;
    tin.resize(n, 0);
    up.resize(n, 0);
    answer.resize(n);
    for (int i = 0; i < n; i++) {
        if (tin[i] == 0)
            find_cut_vertex(i, -1);
    }
    for (int i = 0; i < n; i++)
        count += answer[i];
    cout << count << "\n";
    for (int i = 0; i < n; i++) {
        if (answer[i]) {
            cout << i + 1 << "\n";
        }
    }
}

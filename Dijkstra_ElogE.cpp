#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <set>

using namespace std;

const long long INF = 1e+9;

struct edge {
    int u = -1, w = -1;
};

vector<vector<edge>> graph;
vector<int> dist, parent;

void dijkstra(int start) {
    dist[start] = 0;
    set<pair<int, int>> min_dist;
    min_dist.insert({ 0, start });
    while (!min_dist.empty()) {
        int v = min_dist.begin()->second;
        if (min_dist.begin()->first > dist[v]) {
            min_dist.erase(min_dist.begin());
            continue;
        }
        else min_dist.erase(min_dist.begin());

        for (edge edge : graph[v]) {
            if (dist[edge.u] > dist[v] + edge.w) {
                dist[edge.u] = dist[v] + edge.w;
                min_dist.insert({ dist[edge.u], edge.u });
                parent[edge.u] = v;
            }
        }
    }
}


int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    graph.resize(n);
    dist.resize(n, INF);
    parent.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }

    dijkstra(s);

    if (dist[t] != INF)
        cout << dist[t] << "\n";
    else 
        cout << "-1\n";

    vector<int> ans;
    while (t != s) {
        ans.push_back(t);
        t = parent[t];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    for (int out : ans)
        cout << out + 1 << " ";
}

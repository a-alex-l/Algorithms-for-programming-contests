#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long INF = 1e+9;

struct edge {
    int u = -1, w = -1;
};

struct node {
    int value;
    node *l = this, *r = this;
};

vector<vector<edge>> graph;
vector<int> dist;
vector<node*> pos;

void push(node* root, node* posv) {
    node* now = posv;
    root->r->l = now;
    now->r = root->r;
    root->r = now;
    now->l = root;
}

bool empty(node* root) {
    return root->l == root && root->r == root;
}

void erase(node* del) {
    del->l->r = del->r;
    del->r->l = del->l;
    del->l = del->r = del;
}

node* begin(node* root) {
    return root->r;
}

void bfs_1000_2000(int start, int tail) {
    node    *q_0_999 = new node(),
        *q_1000_1999 = new node(),
        *q_2000_2999 = new node();
    push(q_0_999, pos[start]);
    dist[start] = 0;
    while (!empty(q_0_999) || !empty(q_1000_1999)) {
        if (empty(q_0_999))
            swap(q_0_999, q_1000_1999);
        int v = begin(q_0_999)->value;
        erase(pos[v]);
        for (edge edg : graph[v]) {
            if (dist[edg.u] > edg.w + dist[v] || dist[edg.u] == -1) {
                if (edg.w + dist[v] % 1000 < 2000) {
                    dist[edg.u] = edg.w + dist[v];
                    if (pos[edg.u]->l != pos[edg.u])
                        erase(pos[edg.u]);
                    push(q_1000_1999, pos[edg.u]);
                }
                else {
                    dist[edg.u] = edg.w + dist[v];
                    if (pos[edg.u]->l == pos[edg.u])
                        push(q_2000_2999, pos[edg.u]);
                }
            }
        }
        if (empty(q_0_999)) {
            swap(q_0_999, q_1000_1999);
            swap(q_1000_1999, q_2000_2999);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        graph[x].push_back({ y, w });
    }
    pos.resize(n);
    dist.assign(n, -1);
    for (int i = 0; i < n; i++) {
        pos[i] = new node();
        pos[i]->value = i;
    }
    int x, y;
    cin >> x >> y;
    x--, y--;
    bfs_1000_2000(x, y);
    cout << dist[y] << "\n";
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 1e+9;

vector<int> tree;

int get_max(int i, int left, int right, int inleft, int inright) {
    if (inleft <= left && right <= inright) 
        return tree[i];
    if (right <= inleft || inright <= left)
        return -INF;
    int mid = (left + right) / 2;
    return max(get_max(i * 2 + 1, left, mid, inleft, inright), get_max(i * 2 + 2, mid, right, inleft, inright));
}

int put_elem(int i, int left, int right, int pos, int val) {
    if (pos == left && left == right - 1)
        return tree[i] = val;
    if (pos < left || right <= pos)
        return tree[i];
    int mid = (left + right) / 2;
    return tree[i] = max(put_elem(i * 2 + 1, left, mid, pos, val), put_elem(i * 2 + 2, mid, right, pos, val));
}


int main() {

    int n;
    cin >> n;
    tree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        put_elem(0, 0, n, i, a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char x;
        int a, b;
        cin >> x >> a >> b;
        if (x == 's')
            cout << get_max(0, 0, n, a - 1, b) << " ";
        else
            put_elem(0, 0, n, a - 1, b);
    }
}

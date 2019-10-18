#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> tree;

long long get_sum(int i, int left, int right, int inleft, int inright) {
    if (inleft <= left && right <= inright) 
        return tree[i];
    if (right <= inleft || inright <= left)
        return 0;
    int mid = (left + right) / 2;
    return get_sum(i * 2 + 1, left, mid, inleft, inright) + get_sum(i * 2 + 2, mid, right, inleft, inright);
}

long long put_elem(int i, int left, int right, int pos, long long val) {
    if (pos == left && left == right - 1)
        return tree[i] = val;
    if (pos < left || right <= pos)
        return tree[i];
    int mid = (left + right) / 2;
    return tree[i] = put_elem(i * 2 + 1, left, mid, pos, val) + put_elem(i * 2 + 2, mid, right, pos, val);
}


int main() {
    int n;
    cin >> n;
    tree.resize(4 * n);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        put_elem(0, 0, n, i, a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char x;
        long long a, b;
        cin >> x >> a >> b;
        if (x == 's')
            cout << get_sum(0, 0, n, a - 1, b) << " ";
        else
            put_elem(0, 0, n, a - 1, b);
    }
}

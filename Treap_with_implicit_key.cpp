#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const long long INF = 1e+9;

struct treap {
    int value, y = (rand() << 14) + rand(),
        size_l = 0, size_r = 0;
    treap *l = NULL, *r = NULL;
};

treap * merge(treap *a, treap *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->y < b->y) {
        a->r = merge(a->r, b);
        a->size_r = a->r->size_l + a->r->size_r + 1;
        return a;
    } else {
        b->l = merge(a, b->l);
        b->size_l = b->l->size_l + b->l->size_r + 1;
        return b;
    }
}

pair<treap*, treap*> split(treap *a, int k) {
    if (a == NULL) return { NULL, NULL };
    if (a->size_l < k) {
        pair<treap*, treap*> b = split(a->r, k - a->size_l - 1);
        a->r = NULL, a->size_r = 0;
        return { merge(a, b.first), b.second };
    } else {
        pair<treap*, treap*> b = split(a->l, k);
        a->l = NULL, a->size_l = 0;
        return { b.first, merge(b.second, a) };
    }
}

treap* insert(treap* tree, int pos, int val) {
    treap *add = new treap;
    add->value = val;
    pair<treap*, treap*> a = split(tree, pos);
    return merge(merge(a.first, add), a.second);
}

treap* remove(treap* tree, int pos) {
    pair<treap*, treap*> a = split(tree, pos);
    pair<treap*, treap*> b = split(a.second, 1);
    return merge(a.first, b.second);
}

treap* get(treap* tree, int pos) {
    pair<treap*, treap*> a = split(tree, pos);
    pair<treap*, treap*> b = split(a.second, 1);
    merge(a.first, merge(b.first, b.second));
    return b.first;
}

int main() {
    treap *tree = NULL;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        tree = insert(tree, i - 1, i);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        pair<treap*, treap*> a = split(tree, r), b = split(a.first, l - 1);
        tree = merge(merge(b.second, b.first), a.second);
    }
    for (int i = 0; i < n; i++) {
        treap *now = get(tree, i);
        cout << now->value << " ";
    }
}

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const long long INF = 1e+9;

vector<int> disjoint_set;

void merge(int a, int b) {
    if (rand() % 2) swap(a, b);
    disjoint_set[a] = b;
    return;
}

int find(int x) {
    if (disjoint_set[x] == -1) return x;
    else return disjoint_set[x] = find(disjoint_set[x]);
}

int main() {
    string command;
    while (cin >> command) {
        if (command == "RESET") {
            int n;
            cin >> n;
            disjoint_set.assign(n, -1);
            cout << "RESET DONE\n";
        }
        if (command == "JOIN") {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b)) cout << "ALREADY " << a << " " << b << "\n";
            else merge(find(a), find(b));
        }
        if (command == "CHECK") {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

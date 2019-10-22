#include<iostream>
#include<vector>
#include<string>

using namespace std;

const long long INF = 1e+9;

long long p = 41, mod = 1000099999;
vector<long long> pp;

long long get_hesh(vector<long long> &hesh, int l, int r) {
    if (r < l) return -239;
    return (mod + hesh[r + 1] - hesh[l] * pp[r - l + 1] % mod) % mod;
}

void make_hesh(string &s, vector<long long> &hesh) {
    int n = s.size();
    pp.resize(n + 1, 1);
    hesh.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        pp[i + 1] = (pp[i] * p) % mod;
    for (int i = 0; i < n; i++)
        hesh[i + 1] = ((hesh[i] + (s[i] - 'a' + 1)) * p) % mod;
}


int main() {
    string s, t;
    cin >> s >> t;
    vector<long long> heshs, hesht;
    make_hesh(s, heshs);
    make_hesh(t, hesht);
    int t_size_minus_one = t.size() - 1;
    long long hesh_all_t = get_hesh(hesht, 0, t_size_minus_one);
    int max_pos_start = (int)s.size() - (int)t.size();
    for (int i = 0; i <= max_pos_start; i++) {
        if (get_hesh(heshs, i, i + t_size_minus_one) == hesh_all_t) {
            cout << i << " ";
        }
    }
}

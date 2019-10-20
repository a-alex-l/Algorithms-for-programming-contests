#include<iostream>
#include<vector>
#include<string>

using namespace std;

const long long INF = 1e+9;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref_func(n, 0);
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && s[i] != s[pref_func[j - 1]])
            j = pref_func[j - 1];
        if (j > 0) pref_func[i] = pref_func[j - 1] + 1;
    }
    for (int i = 0; i < n; i++)
        cout << pref_func[i] << " ";
}

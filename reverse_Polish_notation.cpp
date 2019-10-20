#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 1e+9;

vector<int> nambs_actions;

void make() {
    if (-INF <= nambs_actions.back() && nambs_actions.back() <= INF) return;
    if (nambs_actions.back() == -INF - '+') {
        nambs_actions.pop_back();
        make();
        int namb1 = nambs_actions.back();
        nambs_actions.pop_back();
        make();
        nambs_actions.back() += namb1;
        return;
    }
    if (nambs_actions.back() == -INF - '-') {
        nambs_actions.pop_back();
        make();
        int namb1 = nambs_actions.back();
        nambs_actions.pop_back();
        make();
        nambs_actions.back() -= namb1;
        return;
    }
    if (nambs_actions.back() == -INF - '*') {
        nambs_actions.pop_back();
        make();
        int namb1 = nambs_actions.back();
        nambs_actions.pop_back();
        make();
        nambs_actions.back() *= namb1;
        return;
    }
    if (nambs_actions.back() == -INF - '/') {
        nambs_actions.pop_back();
        make();
        int namb1 = nambs_actions.back();
        nambs_actions.pop_back();
        make();
        if (namb1 != 0)
            nambs_actions.back() /= namb1;
        return;
    }
}

int main() {
    string s;
    getline(cin, s);
    s.push_back(' ');
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9' || s[i] == '-' && s[i + 1] != ' ') {
            int j = 0;
            while (s[j + i] != ' ') j++;
            string namber(j + 1, ' ');
            for (j = 0; s[j + i] != ' '; j++)
                namber[j] = s[i + j];
            nambs_actions.push_back(stoi(namber));
            i += j;
            continue;
        }
        if (s[i] != ' ') {
            nambs_actions.push_back(-INF - s[i]);
            i++;
        }
    }
    make();
    cout << nambs_actions[0] << "\n";
}

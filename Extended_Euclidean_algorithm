#include<iostream>

using namespace std;

const long long INF = 1e+9;

void gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0)
        x = 1, y = 0;
    else {
        gcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return;
}


int main() {
    long long a, b, x, y;
    cin >> a >> b;
    gcd(a, b, x, y);
    cout << a * x + b * y << " " << x << " " << y;
}

#include<iostream>

using namespace std;

long long num = 1000000007;

long long func(int n) {
    if (n ==1 ) return 2;
    long long d = func(n / 2) % num;
    if (n & 1) return d * d * 2 % num;
    return d * d % num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 2) cout << 1 << "\n";
        else {
            cout << func(n - 2) << "\n";
        }
    }
}
#include <iostream>
#include<algorithm>
using namespace std;

string to_string(__int128 x) {
    if (x == 0) return "0";
    string s = "";
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        s += '0' + static_cast<char>(x % 10);
        x /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    __int128 L = (n - 1) / 2;
    __int128 U = (n - 1) / 3;
    __int128 a = U + 1;
    __int128 b = L;
    __int128 cnt;
    if (a > b) {
        cnt = 0;
    }
    else {
        __int128 len = b - a + 1;
        __int128 sum_i = (a + b) * len / 2;
        __int128 c = 2 - n;
        __int128 O;

        if (n % 2 == 0) {
            O = ((b + 1) / 2) - (a / 2);
        }
        else {
            O = (b / 2) - ((a - 1) / 2);
        }

        cnt = (3 * sum_i + len * c - O) / 2;
    }

    cout << to_string(cnt);
}
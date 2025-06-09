#include <iostream>
#include <string>
#include <algorithm>
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
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n;
    cin >> n;

    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }

    long long L = (n + 2) / 3;
    long long R = (n - 1) / 2;

    if (L > R) {
        cout << 0 << endl;
        return 0;
    }

    long long total_i = R - L + 1;
    __int128 sum_i = (__int128)(L + R) * total_i / 2;

    long long count_odd = ((R + 1) >> 1) - (L >> 1);
    long long count_ri;
    if ((n + 1) % 2 == 0) {
        count_ri = count_odd;
    }
    else {
        count_ri = total_i - count_odd;
    }

    __int128 term1 = 3 * sum_i;
    __int128 term2 = (1 - (__int128)n) * total_i;
    __int128 total_sum = (term1 + term2 + count_ri) / 2;

    cout << to_string(total_sum) << endl;
    return 0;
}
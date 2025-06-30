#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int dp[100];

long long solve(string s) {
    long long res = 0;
    while (!s.empty()) {
        int len = s.size();

        int num = 0;
        if (len >= 2) {
            num = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
            s.pop_back(); s.pop_back();
        }
        else {
            num = s.back() - '0';
            s.pop_back();
        }
        res += dp[num];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < 100; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i >= 10) dp[i] = min(dp[i], dp[i - 10] + 1);
        if (i >= 25) dp[i] = min(dp[i], dp[i - 25] + 1);
    }

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
}
#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, x;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= k; j++)
        {
            dp[j] += dp[j - v[i]];
        }
    }
    cout << dp[k];
}
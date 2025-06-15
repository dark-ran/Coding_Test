#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

const int SIZE = 1'000'005;
ll arr[SIZE];
vector<ll> lis;
int idx[SIZE];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
            idx[i] = lis.size();
        }
        else {
            *it = arr[i];
            idx[i] = it - lis.begin() + 1;
        }
    }

    ll cnt = lis.size();
    cout << cnt << "\n";

    vector<ll> result;
    for (int i = N - 1; i >= 0 && cnt > 0; i--) {
        if (idx[i] == cnt) {
            result.push_back(arr[i]);
            cnt--;
        }
    }

    reverse(result.begin(), result.end());
    for (ll num : result) {
        cout << num << " ";
    }
}
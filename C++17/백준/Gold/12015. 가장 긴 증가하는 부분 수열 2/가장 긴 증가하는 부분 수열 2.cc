#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, x;
    cin >> N;
    vector<int>lis;

    for (int i = 0; i < N; i++) {
        cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    cout << lis.size();
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x;
    cin >> N;
    vector<int> lis;
    lis.reserve(N);

    for (int i = 0; i < N; i++) {
        cin >> x;
        int lo = 0, hi = lis.size() - 1;
        int pos = lis.size();

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (lis[mid] >= x) {
                pos = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        if (pos == lis.size()) {
            lis.push_back(x);
        }
        else {
            lis[pos] = x;
        }
    }

    cout << lis.size() << flush;
}
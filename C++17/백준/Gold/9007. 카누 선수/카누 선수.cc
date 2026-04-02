#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, K, N;
    cin >> T;

    while (T--) {
        cin >> K >> N;

        vector<int> A(N), B(N), C(N), D(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        for (int i = 0; i < N; i++) cin >> C[i];
        for (int i = 0; i < N; i++) cin >> D[i];

        int sz = N * N;
        vector<int> AB;
        vector<int> CD;
        AB.reserve(sz);
        CD.reserve(sz);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AB.push_back(A[i] + B[j]);
                CD.push_back(C[i] + D[j]);
            }
        }

        sort(AB.begin(), AB.end());
        sort(CD.begin(), CD.end());

        ll best = (ll)AB[0] + CD[0];
        int i = 0;
        int j = (int)CD.size() - 1;

        while (i < (int)AB.size() && j >= 0) {
            ll cur = (ll)AB[i] + CD[j];

            if (llabs((ll)K - cur) < llabs((ll)K - best)) {
                best = cur;
            }
            else if (llabs((ll)K - cur) == llabs((ll)K - best) && cur < best) {
                best = cur;
            }

            if (cur > K) {
                j--;
            }
            else if (cur < K) {
                i++;
            }
            else {
                // 정확히 K면 최적이지만,
                // 같은 차이일 때 더 작은 값을 원한다면 중복 처리 필요
                best = cur;
                j--;
            }
        }

        cout << best << '\n';
    }
}
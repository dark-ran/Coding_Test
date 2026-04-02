#include <iostream>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int A[1001], B[1001], C[1001], D[1001], AB[1'000'001], CD[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, K, N;
    cin >> T;

    while (T--) {
        cin >> K >> N;
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];
        for (int i = 0; i < N; i++) cin >> C[i];
        for (int i = 0; i < N; i++) cin >> D[i];

        int sz = N * N;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AB[i * N + j] = A[i] + B[j];
                CD[i * N + j] = C[i] + D[j];
            }
        }

        sort(AB, AB + sz);
        sort(CD, CD + sz);

        ll best = (ll)AB[0] + CD[0];
        int i = 0;
        int j = sz - 1;

        while (i < sz && j >= 0) {
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
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M;
    cin >> T >> N;

    vector<int>A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    vector<int>B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<long long> A_sum, B_sum;

    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            A_sum.push_back(sum);
        }
    }

    for (int i = 0; i < M; i++) {
        long long sum = 0;
        for (int j = i; j < M; j++) {
            sum += B[j];
            B_sum.push_back(sum);
        }
    }

    sort(A_sum.begin(), A_sum.end());
    sort(B_sum.begin(), B_sum.end());

    long long cnt = 0;
    int i = 0, j = B_sum.size() - 1;

    while (i < A_sum.size() && j >= 0) {
        long long sum = A_sum[i] + B_sum[j];

        if (sum == T) {

            long long cntA = 1, cntB = 1;
            while (i + 1 < A_sum.size() && A_sum[i] == A_sum[i + 1]) {
                cntA++;
                i++;
            }

            while (j - 1 >= 0 && B_sum[j] == B_sum[j - 1]) {
                cntB++;
                j--;
            }

            cnt += cntA * cntB;
            i++;
            j--;
        }
        else if (sum < T) {
            i++;
        }
        else {
            j--;
        }
    }

    cout << cnt;
}
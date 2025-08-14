#include<iostream>
#include<vector>
#include<algorithm>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    cin >> M;

    vector<int> prev(N + 1), curr(N + 1);

    for (int j = M; j <= N; ++j) {
        curr[j] = max(curr[j - 1], arr[j] - arr[j - M]);
    }
    prev = curr;

    fill(curr.begin(), curr.end(), 0);
    for (int j = 2 * M; j <= N; ++j) {
        curr[j] = max(curr[j - 1], prev[j - M] + arr[j] - arr[j - M]);
    }
    prev = curr;

    fill(curr.begin(), curr.end(), 0);
    for (int j = 3 * M; j <= N; ++j) {
        curr[j] = max(curr[j - 1], prev[j - M] + arr[j] - arr[j - M]);
    }

    cout << curr[N];
}
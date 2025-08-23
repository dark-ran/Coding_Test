#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> count(M, 0);
    count[0] = 1;

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        long long num;
        cin >> num;
        sum = (sum + num) % M;
        count[sum]++;
    }

    long long result = 0;
    for (int i = 0; i < M; i++) {
        result += count[i] * (count[i] - 1) / 2;
    }

    cout << result << '\n';
}
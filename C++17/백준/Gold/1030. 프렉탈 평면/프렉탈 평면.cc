#include <iostream>
#include <cmath>
using namespace std;

int isBlack(int N, int K, int x, int y, int size) {
    if (size == 1) return 0;

    int unit = size / N;
    int black_start = (N - K) / 2 * unit; 
    int black_end = black_start + K * unit;

    if (black_start <= x && x < black_end && black_start <= y && y < black_end) {
        return 1;
    }
    return isBlack(N, K, x % unit, y % unit, unit);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, N, K, R1, R2, C1, C2;
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    int size = pow(N, s);

    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << isBlack(N, K, i, j, size);
        }
        cout << "\n";
    }
}
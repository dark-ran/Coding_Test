#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long S, X;
    cin >> S >> X;

    // S < X인 경우, 조건을 만족하는 A, B가 없음
    if (S < X) {
        cout << 0;
        return 0;
    }
    if (S == X) {
        cout << (X == 0 ? 0 : (1LL << __builtin_popcountll(X)) - 2);
        return 0;
    }

    if ((S - X) % 2 == 1) {
        cout << 0;
        return 0;
    }

    long long a = (S - X) / 2;

    if (a & X) { //a와 X의 비트가 안겹쳐야 함
        cout << 0;
        return 0;
    }

    long long count = 1LL << __builtin_popcountll(X);

    cout << count;
}
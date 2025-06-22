#include<iostream>

using namespace std;

const int MAX = 1'000'001;
char s[MAX * 2];
char p[MAX];
int f[MAX];

inline int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    for (int i = 0; i < N; i++)
        cin >> p[i];

    for (int i = 0; i < N; i++)
        s[N + i] = s[i];

    f[0] = 0;
    for (int i = 1, j = 0; i < N; i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        j += (p[i] == p[j]);
        f[i] = j;
    }

    int C = 0;
    for (int i = 0, j = 0; i < 2 * N - 1; i++) {
        while (j > 0 && s[i] != p[j]) j = f[j - 1];
        j += (s[i] == p[j]);
        if (j == N) {
            C++;
            j = f[j - 1];
        }
    }

    int g = gcd(C, N);
    cout << C / g << "/" << N / g;
}
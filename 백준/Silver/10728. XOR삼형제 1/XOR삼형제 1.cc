#include<iostream>

using namespace std;

int main() {
    int T, n, a;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n" << 1 << "\n";
            continue;
        }

        for (a = 1; a <= n; a <<= 1);
        a >>= 1;
        if (a * 3 / 2 <= n) {
            cout << a * 3 / 2 - a / 2 << "\n";
            for (int i = a / 2; i < a * 3 / 2; i++) cout << i << " ";
        }
        else {
            cout << n + 1 - a / 2 << "\n";
            for (int i = a / 2; i <= n; i++) cout << i << " ";
        }
        cout << "\n";
    }
}

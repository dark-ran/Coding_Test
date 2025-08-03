#include <iostream>
using namespace std;

const int MAX = 33554432;
unsigned int vis[(MAX >> 5) + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    while (cin >> a) {
        int idx = a >> 5;
        int bit = a & 31;
        if (!(vis[idx] & (1 << bit))) {
            vis[idx] |= (1 << bit);
            cout << a << ' ';
        }
    }
}

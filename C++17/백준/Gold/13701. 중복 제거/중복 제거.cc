#include <iostream>
#include <bitset>
using namespace std;

bitset<33554433> vis;

int nextInt() {
    char c;
    int a = 0;
    bool is_num = false;
    while (cin.get(c)) {
        if (c >= '0' && c <= '9') {
            a = (a << 3) + (a << 1) + (c - '0');
            is_num = true;
        }
        else if (is_num) {
            return a;
        }
    }

    if (is_num) return a;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a;
    while (true) {
        a = nextInt();
        if (a == -1) break;

        if (!vis[a]) {
            vis[a] = true;
            cout << a << " ";
        }
    }
}
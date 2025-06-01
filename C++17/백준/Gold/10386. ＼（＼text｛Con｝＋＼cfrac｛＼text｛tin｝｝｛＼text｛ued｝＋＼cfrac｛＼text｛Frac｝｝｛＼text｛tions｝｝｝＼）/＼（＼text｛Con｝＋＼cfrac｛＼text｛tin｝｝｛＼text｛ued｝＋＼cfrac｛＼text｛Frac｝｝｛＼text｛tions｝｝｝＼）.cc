#include <iostream>
#define ll long long

using namespace std;

inline ll fabs(ll x) { return x < 0 ? -x : x; }

inline ll fgcd(ll a, ll b) {
    ll r = a;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    r = a;
    return r;
}

inline void print(ll x, ll y) {
    if (y < 0) { x = -x; y = -y; }
    ll g = fgcd(fabs(x), fabs(y));
    x /= g; y /= g;

    if (x < 0) {
        cout << (x / y) - (x % y != 0) << " ";
        x = x % y + (x % y != 0) * y;
    }
    else {
        cout << x / y << " ";
        x %= y;
    }

    while (x != 0) {
        swap(x, y);
        cout << x / y << " ";
        x %= y;
    }
    cout << "\n";
}

void calc(int* r, int n, ll& a, ll& b) {
    a = 1, b = r[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ll t = b;
        b = b * r[i] + a;
        a = t;
        ll g = fgcd(fabs(a), fabs(b));
        a /= g; b /= g;
    }
}

void solve() {
    int r1[10], r2[10];
    ll n1, n2, a1, b1, a2, b2;
    int T = 1;

    while (true) {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0) break;

        for (int i = 0; i < n1; ++i) cin >> r1[i];
        for (int i = 0; i < n2; ++i) cin >> r2[i];

        calc(r1, n1, a1, b1);
        calc(r2, n2, a2, b2);

        cout << "Case " << T++ << ":\n";

        //plus
        ll x = b1 * a2 + b2 * a1;
        ll y = a1 * a2;
        print(x, y);

        //minus
        x = b1 * a2 - b2 * a1;
        y = a1 * a2;
        print(x, y);

        //multiply
        x = b1 * b2;
        y = a1 * a2;
        print(x, y);

        //divide
        x = b1 * a2;
        y = a1 * b2;
        print(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
}
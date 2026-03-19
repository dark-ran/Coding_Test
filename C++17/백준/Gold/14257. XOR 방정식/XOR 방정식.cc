#include<iostream>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	ll S, X;
	cin >> S >> X;
	ll x = X;
	ll cnt_x = 0;

	while (true) {
		if (x & -x) {
			cnt_x++;
			x -= (x & -x);
		}
		else
			break;
	}

	if (S == X) {
		cout << ((1LL << (cnt_x)) - 2);
		return 0;
	}

	ll a = S - X;
	if (S < X || a & 1 || (a>>1) & X) {
		cout << 0;
		return 0;
	}

	cout << (1LL << cnt_x);
}
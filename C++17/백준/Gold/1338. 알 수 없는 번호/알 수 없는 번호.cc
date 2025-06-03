#include<iostream>
#define ll long long

using namespace std;

void swap(ll* a, ll* b) {
	ll t = *a;
	*a = *b;
	*b = t;
}

ll absl(ll x) {
	return x > 0 ? x : -x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, x, y, front, back;
	cin >> a >> b >> x >> y;

	if (y < 0 || y >= absl(x)) {
		cout << "Unknwon Number";
		return 0;
	}

	if(a>b)
		swap(&a, &b);

	x = absl(x);

	ll k = (a / x - 1) * x;
	
	while (a > k + y) {
		k += x;
	}

	if (k + y > b) {
		cout << "Unknwon Number";
		return 0;
	}
	else if (k + y + x <= b) {
		cout << "Unknwon Number";
		return 0;
	}
	else cout << k + y;
}
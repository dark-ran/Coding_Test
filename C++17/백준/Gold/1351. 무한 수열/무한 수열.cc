#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

unordered_map<ll, ll>ma;

ll func(ll N, ll P, ll Q) {
	if (ma[N])
		return ma[N];
	return ma[N] = func(N / P, P, Q) + func(N / Q, P, Q);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	ll N, P, Q;
	cin >> N >> P >> Q;
	ma[0] = 1;
	ll res = func(N, P, Q);
	cout << res;
}
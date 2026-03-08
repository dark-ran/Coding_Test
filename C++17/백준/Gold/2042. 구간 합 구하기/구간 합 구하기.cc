#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll sum(vector<ll>& tree, int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

void update(vector<ll>& tree, int idx, ll v) {
	while (idx < tree.size()) {
		tree[idx] += v;
		idx += (idx & -idx);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	vector<ll>arr(N + 1), tree(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		update(tree, i, arr[i]);
	}
	M += K;
	while (M--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - arr[b];
			arr[b] += diff;
			update(tree, b, diff);
		}
		else {
			cout << sum(tree, c) - sum(tree, b - 1) << "\n";
		}
	}
}
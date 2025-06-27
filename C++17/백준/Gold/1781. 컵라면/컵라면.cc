#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

int parent[200'001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<pii>v(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { b,a };
	}

	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i <= 200'000; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int slot = find(v[i].second);
		if (slot > 0) {
			sum += v[i].first;
			parent[slot] = slot - 1;
		}
	}

	cout << sum << flush;
}
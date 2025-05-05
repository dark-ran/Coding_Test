#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, E;
	cin >> N >> E;
	vector<int>v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int cnt = 1;
	for (int i = 0; i < N - 1; i++) {
		if (v[i + 1] - v[i] < E)continue;
		cnt++;
	}
	cout << cnt;
}
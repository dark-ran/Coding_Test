#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	vector<int>arr(N);
	for (int i = 0;i < N;i++)
		cin >> arr[i];

	map<vector<int>,int>ma;
	ma[arr] = 0;
	queue<vector<int>>q;
	q.push(arr);
	sort(arr.begin(), arr.end());

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur == arr) {
			cout << ma[arr] << flush;
			return 0;
		}

		int cnt = ma[cur];
		for (int i = 0;i <= N - K;i++) {
			vector<int>next = cur;
			int s = i;
			int e = i + K - 1;
			while (s < e) {
				int t = next[s];
				next[s] = next[e];
				next[e] = t;
				s++, e--;
			}
			
			if (ma.find(next) == ma.end()) {
				ma[next] = cnt + 1;
				q.push(next);

			}
		}
	}
	cout << "-1" << flush;
}
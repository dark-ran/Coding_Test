#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, a, b;
	cin >> N;
	vector<pair<int, int>>arr(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	arr[N] = { 1'234'567,0 };
	cin >> a >> b;

	sort(arr.begin(), arr.end());
	priority_queue<int>pq;
	int st = 0;
	int cnt = 0;
	while (a > b) {
		while (arr[st].first <= b) {
			pq.push(arr[st].second);
			st++;
		}
        
		if (!pq.empty()) {
			b += pq.top();
			pq.pop();
			cnt++;
		}
		else {
			cout << -1 << flush;
			return 0;
		}
	}
	cout << cnt << flush;
}
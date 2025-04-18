#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // { 시간, 위치 }
	vector<bool>v(200000, false);
	pq.push({ 0,N });
	while (!pq.empty()) {
		int ti = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur == K) {
			cout << ti;
			break;
		}
		if (cur < K && !v[cur * 2]) {
			pq.push({ ti,cur * 2 });
			v[cur * 2] = true;
		}
		if (cur < K && !v[cur + 1]) {
			pq.push({ ti + 1,cur + 1 });
			v[cur + 1] = true;
		}
		if (cur > 0 && !v[cur - 1]) {
			pq.push({ ti + 1,cur - 1 });
			v[cur - 1] = true;
		}
	}
}
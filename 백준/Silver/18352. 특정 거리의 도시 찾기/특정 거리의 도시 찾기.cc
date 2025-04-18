#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, k, x;
vector<int>arr[300001];
int city[300001];
void bfs(int idx) {
	city[idx] = 0;
	queue<int>q;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		for (int i = 0; i < arr[idx].size(); i++) {
			if (city[arr[idx][i]] == -1) {
				q.push(arr[idx][i]);
				city[arr[idx][i]] = city[idx] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++)
		city[i] = -1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}
	bfs(x);
	priority_queue<int,vector<int>,greater<int>>pq;
	for (int i = 1; i <= n; i++)
		if (city[i] == k)
			pq.push(i);
	if (pq.empty())
		cout << -1;
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}

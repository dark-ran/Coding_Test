#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>v(N);
	vector<int>num(N);
	while (M--) {
		int s, e;
		cin >> s >> e;
		v[s - 1].push_back(e - 1);
		num[e - 1]++;
	}

	priority_queue<int, vector<int>, greater<>>q;
	for (int i = 0;i < N;i++)
		if (num[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.top();
		cout << cur + 1 << " ";
		q.pop();
		for (auto a : v[cur]) {
			num[a]--;
			if (num[a] == 0)
				q.push(a);
		}
	}
}
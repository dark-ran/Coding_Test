#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>sub(N + 1);
	vector<int>num(N + 1);
	for (int i = 0;i < M;i++) {
		int n, pre, cur;
		cin >> n;
		if (n > 0)
			cin >> pre;

		for (int j = 1;j < n;j++) {
			cin >> cur;
			sub[pre].push_back(cur);
			num[cur]++;
			pre = cur;
		}
	}
	vector<int>res;
	queue<int>q;
	for (int i = 1;i <= N;i++)
		if (num[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (int a : sub[cur]) {
			if (--num[a] == 0) {
				q.push(a);
			}
		}
	}
	if (res.size() != N) {
		cout << "0" << flush;
	}
	else {
		for (int a : res) {
			cout << a << "\n";
		}
	}

}
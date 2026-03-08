#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int>par(N);
	vector<vector<int>>child(N, vector<int>());//input
	for (int i = 0; i < N; i++) {
		cin >> par[i];
		if (par[i] != -1) {
			child[par[i]].push_back(i);
		}
	}

	int x;
	cin >> x;
	if (par[x] != -1 && child[par[x]].size() == 1)
		child[par[x]].clear();
	queue<int>q;
	q.push(x);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for(int c:child[now])
			q.push(c);
		if (child[now].empty()) 
			child[now].push_back(-1);
	}
	int sum = 0;
	for (int i = 0;i < N;i++) {
		if(child[i].empty())
			sum++;
	}
	cout << sum;
}
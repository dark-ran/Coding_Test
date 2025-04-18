#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

pair<int,int> a[200003];
priority_queue<int,vector<int>,greater<int>>pq;

int func(int num) {
	pq.push(a[0].second);
	for (int i = 1; i < num; i++) {
		if (a[i].first >= pq.top()) {
			pq.pop();
			pq.push(a[i].second);
		}
		else {
			pq.push(a[i].second);
		}
	}
	return pq.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	cout<<func(n);
}
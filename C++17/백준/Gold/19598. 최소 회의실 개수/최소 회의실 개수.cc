#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<>> q;
	q.push(v[0].second);
	int m = 1;
	for (int i = 1; i < N; i++){
		while (!q.empty() && q.top() <= v[i].first)
			q.pop();
		q.push(v[i].second);
		m = m > q.size() ? m : q.size();
	}
	cout << m;
}
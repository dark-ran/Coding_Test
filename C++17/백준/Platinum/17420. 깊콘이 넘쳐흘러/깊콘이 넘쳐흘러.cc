#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define ll long long
#define pii pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>A(N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	priority_queue<pii, vector<pii>, greater<pii>>pq;
	ll res = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] < B[i]) {
			ll cnt = (B[i] - A[i] + 29) / 30;
			res += cnt;
			A[i] += (cnt * 30);
		}
		pq.push({ B[i],A[i] });
	}

	ll sum = 0;
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (sum > cur.second) {
			ll cnt = (sum - cur.second + 29) / 30;
			res += cnt;
			cur.second += cnt * 30;
			pq.push(cur);
		}
		else {
			sum = cur.second;
		}
	}
	cout << res;
}
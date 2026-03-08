#include<iostream>
#include<queue>

using namespace std;

bool a[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K;
	pair<int,int> cur;
	cin >> N >> K;
	queue<pair<int,int>>q;
	q.push({ N,0 });
	a[N] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.first == K) break;

		if (cur.first + 1 < 100001) {
			if (!a[cur.first + 1]) {
				a[cur.first + 1] = true;
				q.push({ cur.first + 1,cur.second + 1 });
			}
		}
		if (cur.first - 1 >= 0) {
			if (!a[cur.first - 1]) {
				a[cur.first - 1] = true;
				q.push({ cur.first - 1,cur.second + 1 });
			}
		}

		if (cur.first * 2 < 100001) {
			if (!a[cur.first * 2]) {
				a[cur.first * 2] = true;
				q.push({ cur.first * 2,cur.second + 1 });
			}
		}
	}
	cout << cur.second;
}
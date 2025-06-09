#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, a, b;
	cin >> N;
	vector<unordered_set<int>>v(N);
	for (int i = 0;i < N - 1;i++) {
		cin >> a >> b;
		v[a - 1].insert(b - 1);
		v[b - 1].insert(a - 1);
	}

	stack<int>q;
	vector<bool>vis(N);

	cin >> a;
	if (a != 1) {
		cout << "0";
		return 0;
	}
	a--;
	q.push(a);
	vis[a] = true;
	for (int i = 1;i < N;i++) {
		cin >> a;
		a--;
		if (vis[a]) { //이미 방문했다면
			cout << "0";
			return 0;
		}
		bool found = false;
		while (!q.empty()) {
			int cur = q.top();
			if (v[cur].count(a)) {
				v[cur].erase(a);
				v[a].erase(cur);

				q.push(a);
				vis[a] = true;
				found = true;
				break;
			}
			else {
				q.pop();
			}
		}
		if (!found) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
}
#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

struct cmp {
	bool operator()(const pii& a, const pii& b) {
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, M, x, y;
		cin >> N;
		vector<int>arr(N); //저번 i의 위치
		vector<int>nex(N); //현재 i의 위치 
		for (int i = 0;i < N;i++) {
			cin >> x;
			arr[x - 1] = i;
			nex[x - 1] = i;
		}
		cin >> M;
		while (M--) {
			cin >> x >> y;
			if (arr[x - 1] > arr[y - 1]) {
				int t = x;
				x = y;
				y = t;
			}
			nex[x - 1]++;
			nex[y - 1]--;
		}
		vector<pii>pi(N);
		for (int i = 0;i < N;i++) {
			pi[i] = { i,nex[i] };
		}
		sort(pi.begin(), pi.end(), cmp());
		bool flag = true;
		for (int i = 0;i < N;i++) {
			if (pi[i].second != i) {
				cout << "IMPOSSIBLE\n";
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = 0;i < N;i++)
				cout << pi[i].first + 1 << " ";
			cout << "\n";
		}
	}
}
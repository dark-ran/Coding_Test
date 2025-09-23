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
		vector<pii>nex(N); //다음 i의 위치
		for (int i = 0;i < N;i++) {
			cin >> x;
			arr[x - 1] = i;
			nex[x - 1].second = i;
			nex[x - 1].first = x;
		}
		cin >> M;
		while (M--) {
			cin >> x >> y;
			if (arr[x - 1] > arr[y - 1]) {
				int t = x;
				x = y;
				y = t;
			}
			nex[x - 1].second++;
			nex[y - 1].second--;
		}
		
		sort(nex.begin(), nex.end(), cmp());
		bool flag = true;
		for (int i = 0;i < N;i++) {
			if (nex[i].second != i) {
				cout << "IMPOSSIBLE\n";
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = 0;i < N;i++)
				cout << nex[i].first << " ";
			cout << "\n";
		}
	}
}
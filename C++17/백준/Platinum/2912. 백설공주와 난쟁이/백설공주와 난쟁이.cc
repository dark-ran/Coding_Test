#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, C, M;
	cin >> N >> C;
	vector<int>arr(N + 1);
	vector<vector<int>>idx(C + 1);
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		idx[arr[i]].push_back(i);
	}

	cin >> M;
	while (M--) {
		int l, r;
		cin >> l >> r;
		bool flag = false;
		for (int i = 0;i < 20;i++) {
			int num = l + rand() % (r - l + 1);
			int c = arr[num];
			int cnt = upper_bound(idx[c].begin(), idx[c].end(), r) - lower_bound(idx[c].begin(), idx[c].end(), l);
			if (cnt > ((r - l + 1) >> 1)) {
				cout << "yes " << c << "\n";
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "no\n";
	}
}
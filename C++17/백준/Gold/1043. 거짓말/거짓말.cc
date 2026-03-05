#include<iostream>
#include<vector>

using namespace std;

int par[51];

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void _union(int x, int y) {
	x = find(x);
	y = find(y);
	par[x] = par[y];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M, K, x, y, z;
	cin >> N >> M >> K;
	if (K == 0) {
		cout << M;
		return 0;
	}

	for (int i = 1;i <= N;i++)
		par[i] = i;

	vector<int>know_people;
	for (int i = 0;i < K;i++) {
		cin >> x;
		know_people.push_back(x);
	}

	vector<vector<int>>party(M);
	for (int i = 0;i < M;i++) {
		cin >> x >> y;
		party[i].push_back(y);
		for (int j = 1;j < x;j++) {
			cin >> z;
			party[i].push_back(z);
			_union(y, z);
		}
	}

	int res = M;
	for (auto people : party) {
		bool flag = false;
		for (auto person : people) {
			if (flag)
				break;
			for (auto know_person : know_people) {
				if (find(person) == find(know_person)) {
					flag = true;
					break;
				}
			}
		}
		if (flag)
			res--;
	}

	cout << res;
}
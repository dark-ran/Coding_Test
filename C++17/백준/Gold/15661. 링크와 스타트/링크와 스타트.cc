#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v[20][20];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> v[i][j];
			v[i][j] += v[j][i];
		}

	int l = 1 << N - 1;
	int res = 1987654321;
	for (int i = 1;i < l;i++) {
		vector<int>start;
		vector<int>link;
		for (int j = 0;j < N;j++) {
			if (i & (1 << j))
				start.push_back(j);
			else
				link.push_back(j);
		}

		int start_point = 0, link_point = 0;
		for (int j = 0;j < start.size();j++)
			for (int k = j + 1;k < start.size();k++)
				start_point += v[start[k]][start[j]];

		for (int j = 0;j < link.size();j++)
			for (int k = j + 1;k < link.size();k++)
				link_point += v[link[k]][link[j]];

		res = res < abs(start_point - link_point) ? res : abs(start_point - link_point);
	}
	cout << res;
}
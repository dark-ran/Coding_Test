#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct s {
	int color, size, idx;
};
bool cmp(s& a, s& b) {
	return a.size < b.size;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<s>query(N);
	for (int i = 0;i < N;i++) {
		cin >> query[i].color >> query[i].size;
		query[i].idx = i;
	}

	sort(query.begin(), query.end(), cmp);

	vector<int>ans(N);
	vector<int>color(N);
	int sum = 0;
	for (int i = 0, j = 0;i < N;i++) {
		while (query[i].size > query[j].size) {
			sum += query[j].size;
			color[query[j].color - 1] += query[j].size;
			j++;
		}

		ans[query[i].idx] = sum - color[query[i].color - 1];
	}

	for (int i = 0;i < N;i++)
		cout << ans[i] << "\n";
}
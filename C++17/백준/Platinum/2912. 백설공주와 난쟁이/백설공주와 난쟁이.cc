#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[300'001];
int color[10'001];
int ans[10'001];
int sqrt_N;

struct s {
	int l, r, idx;
};

bool cmp(s& a, s& b) {
	if (a.l / sqrt_N != b.l / sqrt_N)
		return a.l / sqrt_N < b.l / sqrt_N;
	return a.r < b.r;
}

void QueryDel(int s, int e) {
	for (int i = s;i <= e;i++)
		color[arr[i]]--;
}

void QueryAdd(int s, int e) {
	for (int i = s;i <= e;i++)
		color[arr[i]]++;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, C, M;
	cin >> N >> C;
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	sqrt_N = sqrt(N);

	cin >> M;
	vector<s>query(M);
	for (int i = 0;i < M;i++) {
		cin >> query[i].l >> query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].idx = i;
	}

	sort(query.begin(), query.end(), cmp);

	int l = query[0].l;
	int r = query[0].r;
	int max_num = 0;
	int max_col = 0;
	for (int i = l;i <= r;i++) {
		if (max_num < ++color[arr[i]]) {
			max_num = color[arr[i]];
			max_col = arr[i];
		}
	}
	if (max_num > (query[0].r - query[0].l + 1) >> 1)
		ans[query[0].idx] = max_col;

	for (int i = 1;i < M;i++) {
		while (l < query[i].l) color[arr[l++]]--;
		while (l > query[i].l) color[arr[--l]]++;
		while (r < query[i].r) color[arr[++r]]++;
		while (r > query[i].r) color[arr[r--]]--;

		max_col = 0;
		max_num = 0;
		for (int j = 1;j <= C;j++) {
			if (max_num < color[j]) {
				max_num = color[j];
				max_col = j;
			}
		}

		if (max_num > (query[i].r - query[i].l + 1) >> 1)
			ans[query[i].idx] = max_col;
	}

	for (int i = 0;i < M;i++) {
		if (ans[i])
			cout << "yes " << ans[i] << "\n";
		else
			cout << "no\n";
	}
}
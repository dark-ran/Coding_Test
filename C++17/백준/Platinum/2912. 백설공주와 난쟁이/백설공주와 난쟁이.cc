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

	int l = 0;
	int r = -1;

	for (int i = 0;i < M;i++) {
		while (l < query[i].l) color[arr[l++]]--;
		while (l > query[i].l) color[arr[--l]]++;
		while (r < query[i].r) color[arr[++r]]++;
		while (r > query[i].r) color[arr[r--]]--;

		int mid = (r - l + 1) >> 1;
		for (int j = 1;j <= C;j++) {
			if (mid < color[j]) {
				ans[query[i].idx] = j;
				break;
			}
		}
	}

	for (int i = 0;i < M;i++) {
		if (ans[i])
			cout << "yes " << ans[i] << "\n";
		else
			cout << "no\n";
	}
}
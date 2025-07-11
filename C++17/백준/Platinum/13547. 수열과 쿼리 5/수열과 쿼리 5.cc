#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int arr[100'001];
int cnt[1'000'001];
int ans[100'001];
int now = 0;
int ground;

struct query {
	int idx, s, e;
};
bool compare(const query&l, const query&r) {
	if (l.s/ground != r.s/ground)
		return l.s / ground < r.s / ground;
	return l.e < r.e;
}
void QueryAdd(int s, int e) {
	for (int i = s;i <= e;i++) {
		if (!cnt[arr[i]]) now++;
		cnt[arr[i]]++;
	}
}
void QueryDel(int s, int e) {
	for (int i = s;i <= e;i++) {
		if (--cnt[arr[i]] == 0) now--;
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	ground = sqrt(N);

	cin >> M;
	vector<query>q(M);
	for (int i = 0;i < M;i++) {
		cin >> q[i].s >> q[i].e;
		q[i].s--, q[i].e--;
		q[i].idx = i;
	}

	sort(q.begin(), q.end(),compare);
	int left = q[0].s, right = q[0].e;
	for (int i = left; i <= right; i++) {
		if (!cnt[arr[i]]) now++;
		cnt[arr[i]]++;
	}
	ans[q[0].idx] = now;

	for (int i = 1;i < M;i++) {
		if (q[i].s < left) QueryAdd(q[i].s, left - 1);
		else if (q[i].s > left) QueryDel(left, q[i].s - 1);

		if (q[i].e > right) QueryAdd(right + 1, q[i].e);
		else if (q[i].e < right) QueryDel(q[i].e + 1, right);

		left = q[i].s;
		right = q[i].e;
		ans[q[i].idx] = now;
	}
	for (int i = 0;i < M;i++) {
		cout << ans[i] << "\n";
	}
}
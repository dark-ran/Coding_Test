#include<iostream>
#include<vector>
#include<algorithm>
#define size 100002

using namespace std;

struct Query {
	int x, y, z, id;
};
bool comp(pair<int, int>a, pair<int, int>b) { return a.first > b.first; }
bool coms(Query& a, Query& b) { return a.z > b.z; }

int N, M;
int tree[size], res[size];
Query q[size];
pair<int, int>arr[size];

void add(int x) {
	while (x <= N) {
		tree[x]++;
		x += (x & -x);
	}
}

int sum(int x) {
	int r = 0;
	while (x > 0) {
		r += tree[x];
		x -= (x & -x);
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> q[i].x >> q[i].y >> q[i].z;
		q[i].id = i;
	}
	sort(arr + 1, arr + N + 1, comp);
	sort(q + 1, q + M + 1, coms);
	int c = 1;
	for (int i = 1; i <= M; i++) {
		for (; c <= N; c++) {
			if (arr[c].first > q[i].z) 
				add(arr[c].second);
			else break;
		}
		res[q[i].id] = sum(q[i].y) - sum(q[i].x - 1);
	}
	for (int i = 1; i <= M; i++)cout << res[i] << "\n";
}
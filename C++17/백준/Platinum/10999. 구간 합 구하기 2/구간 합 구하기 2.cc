#include<iostream>
#define ll long long

using namespace std;

ll tree[4000004];
ll lazy[4000004];
ll arr[1000001];

void init(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void push(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void modify(int node, int start, int end, int x, int y, long long z) {
	push(node, start, end);
	if (y < start || end < x) return;
	if (x <= start && end <= y) {
		tree[node] += (end - start + 1) * z;
		if (start != end) {
			lazy[node * 2] += z;
			lazy[node * 2 + 1] += z;
		}
		return;
	}
	int mid = (start + end) / 2;
	modify(node * 2, start, mid, x, y, z);
	modify(node * 2 + 1, mid + 1, end, x, y, z);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int node, int start, int end, int x, int y) {
	push(node, start, end);
	if (y < start || end < x) return 0;
	if (x <= start && end <= y) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll left = sum(node * 2, start, mid, x, y);
	ll right = sum(node * 2 + 1, mid + 1, end, x, y);
	return left + right;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	init(1, 0, N - 1);
	int Q = M + K;
	int a, b, c;
	long long d;
	while (Q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			modify(1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			cout << sum(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
}
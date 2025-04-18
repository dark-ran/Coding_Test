#include<iostream>

using namespace std;

long long tree[2000001];
int N;

void modi(int idx, long long diff) {
	idx = idx + N - 1;
	while (idx) { //부모에게 계속 차이만큼 값 추가
		tree[idx] += diff;
		idx >>= 1;
	}
}

long long sum(int l, int r) {
	long long res = 0;
	l = l + N - 1;
	r = r + N - 1;
	while (l <= r) {
		if (l & 1)res += tree[l++];
		if (!(r & 1))res += tree[r--];
		l >>= 1;
		r >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int K, M;
	cin >> N >> K >> M;
	for (int i = N; i < N * 2; i++)cin >> tree[i];
	for (int i = N - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
	int Q = K + M;
	long long a, b, c;
	while (Q--) {
		cin >> a >> b >> c;
		if (a == 1)
			modi(b, c - tree[b + N - 1]);
		else
			cout << sum(b, c) << "\n";
	}
}
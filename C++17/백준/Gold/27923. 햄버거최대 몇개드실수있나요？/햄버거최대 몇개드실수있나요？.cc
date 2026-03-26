#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int func(int x , int y) {
	for (;y && x;y--)
		x >>= 1;
	return x;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K, L, x;
	cin >> N >> K >> L;
	vector<int>m(N), t(N + 1);
	for (int i = 0;i < N;i++)
		cin >> m[i];
	for (int i = 0;i < K;i++) {
		cin >> x;
		t[x]++;
		if (x + L <= N)
			t[x + L]--;
	}
	
	for (int i = 1;i <= N;i++)//누적합 계산
		t[i] += t[i - 1];

	sort(m.begin(), m.end());
	sort(t.begin(), t.end());
	long long sum = 0;
	for (int i = 0;i < N;i++) {
		int a = func(m[i], t[i + 1]);
		sum += a;
	}
	cout << sum;
}

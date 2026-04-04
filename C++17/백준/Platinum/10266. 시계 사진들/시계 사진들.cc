#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, x;
	cin >> N;
	bitset<360'000>check;
	vector<int>A(N * 2), B(N);

	for (int i = 0;i < N;i++) {
		cin >> x;
		check[x] = true;
	}
	for (int i = 0, j = 0, prv = -1, st = -1;i <= 360'000;i++) {
		if (i<360'000 && !check[i]) continue;
		if (prv != -1) A[j++] = (j == N - 1 ? 360'000 - prv + st : i - prv);
		else st = i;
		prv = i;
	}

	check.reset();

	for (int i = 0;i < N;i++) {
		cin >> x;
		check[x] = true;
	}

	for (int i = 0, j = 0, prv = -1, st = -1;i <= 360'000;i++) {
		if (i<360'000 && !check[i]) continue;
		if (prv != -1) B[j++] = (j == N - 1 ? 360'000 - prv + st : i - prv);
		else st = i;
		prv = i;
	}

	for (int i = 0;i < N;i++)
		A[i + N] = A[i];
	
	vector<int>f(N);
	for (int i = 1, j = 0;i < N;i++) {
		while (j > 0 && B[i] != B[j])
			j = f[j - 1];
		if (B[i] == B[j])
			f[i] = ++j;
	}

	for (int i = 0, j = 0;i < (N << 1);i++) {
		while (j > 0 && A[i] != B[j])
			j = f[j - 1];
		if (A[i] == B[j]) {
			if (++j == N) {
				cout << "possible";
				return 0;
			}
		}
	}
	cout << "impossible";
}
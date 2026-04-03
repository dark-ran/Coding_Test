#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int>f(n, false);
	vector<int>A(n * 2), B(n);

	for (int i = 0;i < n;i++)
		cin >> A[i];
	for (int i = 0;i < n;i++)
		cin >> B[i];

	sort(A.begin(), A.begin() + n);
	sort(B.begin(), B.end());

	int a = A[n - 1], b = B[n - 1];
	for (int i = n - 1;i > 0;i--) {
		A[i] -= A[i - 1];
		B[i] -= B[i - 1];
	}
	A[0] = A[0] + 360000 - a;
	B[0] = B[0] + 360000 - b;

	for (int i = n;i < 2 * n;i++)
		A[i] = A[i - n];

	int j = 0;
	for (int i = 1;i < n;i++) {
		while (j > 0 && B[i] != B[j])
			j = f[j - 1];
		if (B[i] == B[j])
			f[i] = ++j;
	}

	b = 0;
	for (a = 0;a < n * 2;a++) {
		while (b > 0 && A[a] != B[b])
			b = f[b - 1];
		if (A[a] == B[b]) {
			if (++b == n) {
				cout << "possible";
				return 0;
			}
		}
	}
	cout << "impossible";
	return 0;
}
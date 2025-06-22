#include<iostream>

using namespace std;

const int MAX = 1'000'001;
char s[2 * MAX];
char p[MAX];
int f[MAX];

int gcd(int a, int b) {
	int r = a % b;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> s[i];
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		s[N + i] = s[i];
	}

	f[0] = 0;
	int j = 0;
	for (int i = 1; i < N; i++) {
		while (j > 0 && p[i] != p[j])j = f[j - 1];
		if (p[j] == p[i])f[i] = ++j;
		else f[i] = 0;
	}
	
	int C = 0;
	int M = N;
	for (int i = 0, j = 0; i < 2 * N - 1; i++) {
		while (j > 0 && s[i] != p[j])j = f[j - 1];
		if (s[i] == p[j]) j++;
		if (j == N) {
			C++;
			j = f[j - 1];
		}
	}
	
	int a = gcd(C, M);
	cout << C / a << "/" << M / a;
}
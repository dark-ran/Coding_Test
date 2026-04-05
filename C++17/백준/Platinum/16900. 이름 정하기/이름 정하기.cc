#include<iostream>
#define ll long long

using namespace std;

int f[500'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	for (int i = 1, j = 0;i < n;i++) {
		while (j > 0 && s[i] != s[j])
			j = f[j - 1];
		if (s[i] == s[j])
			f[i] = ++j;
	}
	cout << ((ll)n - f[n - 1]) * k + f[n - 1];
}
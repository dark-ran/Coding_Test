#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;
	cin >> s;
	int n = s.size();
	int res = 0;
	for (int k = 0;k < n;k++) {
		vector<int>f(n);
		int j = k;
		for (int i = k + 1;i < n;i++) {
			while (j > k && s[i] != s[j])
				j = f[j - 1] + k;
			if (s[i] == s[j])
				f[i] = ++j - k;
			res = (res > f[i] ? res : f[i]);
		}
	}
	cout << res;
}
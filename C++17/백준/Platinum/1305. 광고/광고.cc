#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int L;
	cin >> L;
	string S;
	cin >> S;
	int j = 0;
	vector<int>f(S.size(), false);
	for (int i = 1;i < S.size();i++) {
		while (j > 0 && S[i] != S[j])
			j = f[j - 1];
		if (S[i] == S[j])
			f[i] = ++j;
	}
	cout << L - f[S.size() - 1];
}
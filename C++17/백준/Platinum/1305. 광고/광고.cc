#include<iostream>

using namespace std;

int f[1'000'001];
string S;
int L;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> L >> S;
	int j = 0;
	for (int i = 1;i < S.size();i++) {
		while (j > 0 && S[i] != S[j])
			j = f[j - 1];
		if (S[i] == S[j])
			f[i] = ++j;
	}
	cout << L - f[S.size() - 1];
}
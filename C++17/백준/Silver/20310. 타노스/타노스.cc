#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	int zero = 0, one = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]=='1') one++;
		else zero++;
	}
	int idx = 0;
	int size = s.length();
	zero >>= 1;
	one >>= 1;
	string res;
	while (idx < size) {
		if (s[idx]=='0') {
			if (zero>0) {
				zero--;
			}
			else {
				idx++;
				continue;
			}
		}
		else {
			if (one>0) {
				one--;
				idx++;
				continue;
			}
		}
		res += s[idx++];
	}
	cout << res;
}
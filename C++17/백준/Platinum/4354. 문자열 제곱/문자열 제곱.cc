#include<iostream>

using namespace std;

int f[1'000'000];
int l;

void make_f(string&s) {
	for (int i = 1, j = 0; i < l; i++) {
		while (j > 0 && s[i] != s[j])j = f[j - 1];
		j += (s[i] == s[j]);
		f[i] = j;
	}	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	while (1) {
		cin >> s;
		l = s.length();
		if (s == ".") return 0;
		make_f(s);
		int rep = l - f[l - 1];
		if (l % rep) {
			cout << 1 << "\n";
		}
		else {
			cout << l / rep << "\n";
		}
	}
}
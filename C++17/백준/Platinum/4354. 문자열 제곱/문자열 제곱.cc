#include<iostream>

using namespace std;

static const int ISIZE = 1 << 24;
static char ibuf[ISIZE];
static char* in_ptr;
static char* end_ptr;
inline char get() {
	if (in_ptr == end_ptr) {
		end_ptr = ibuf + fread(ibuf, 1, ISIZE, stdin);
		in_ptr = ibuf;
	}
	return *in_ptr++;
}
string next_string() {
	string s;
	char c;
	while ((c = get()) < '.');
	if (c == '.')return ".";
	for (; c >= 'a'; c = get()) {
		s += c;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	while (1) {
		s = next_string();
		int l = s.size();
		if (s == ".") return 0;
		if (l == 1) {
			cout << "1\n";
			continue;
		}
		int cnt = 0;
		for (int i = 1, j = 0; i < l; i++) {
			if (s[i] == s[j]) {
				cnt++;
				j++;
			}
			else {
				cnt = 0;
				j = 0;
				if (s[i] == s[j]) {
					cnt = 1;
					j++;
				}
			}
		}

		int rep = l - cnt;
		if (l % rep) {
			cout << "1\n";
		}
		else {
			cout << l / rep << "\n";
		}
	}
}
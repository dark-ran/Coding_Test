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

int f[1'000'000];
int l;

void make_f(string&s) {
	for (int i = 1, j = 0; i < l; i++) {
		if (s[i] == s[j]) {
			f[i] = f[i - 1] + 1;
			j++;
		}
		else {
			f[i] = 0;
			j = 0;
			if (s[i] == s[j]) {
				f[i] = 1;
				j++;
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	while (1) {
		s = next_string();
		l = s.length();
		if (s == ".") return 0;
		if (l == 1) {
			cout << "1\n";
			continue;
		}
		make_f(s);
		int rep = l - f[l - 1];
		if (l % rep) {
			cout << "1\n";
		}
		else {
			cout << l / rep << "\n";
		}
	}
}
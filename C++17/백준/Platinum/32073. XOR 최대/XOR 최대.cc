#include<iostream>
#include<string>

using namespace std;

const int ISIZE = 1 << 22;
char ibuf[ISIZE];
char* in_ptr = ibuf;
char* end_ptr = ibuf;
char get() {
	if (in_ptr == end_ptr) {
		end_ptr = ibuf + fread(ibuf, 1, ISIZE, stdin);
		in_ptr = ibuf;
	}
	return *in_ptr++;
}
void nextInt(int& x) {
	x = 0;
	char c;
	while ((c = get()) < '0');
	for (; c >= '0'; c = get()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
}
void nextStr(string& s) {
	s = "";
	char c;
	while ((c = get()) < '0');
	for (; c >= '0'; c = get()) {
		s += c;
	}
}


string XOR(string& s1, string s2) {
	if (s2.size() < s1.size())
		s2 = string(s1.size() - s2.size(), '0') + s2;
	for (int i = 0; i < s1.size(); i++)
		s1[i] = (s1[i] != s2[i] ? '1' : '0');
	int x = s1.find('1');
	if (x == string::npos) return "0";
	return s1.substr(x);
}

string func(int N, string& S) {
	if (S.find('0') == string::npos) {
		S.back() = '0';
		return S;
	}
	int pos = S.find('1');
	if (pos == string::npos) {
		return "0";
	}

	int len = 0;
	while (pos + len < N && S[pos + len] == '1')
		len++;
	int idx = pos + len;
	for (int i = 0; i <= len && i + idx < S.length(); i++) {
		if (S[i + idx] == '1') {
			return XOR(S, S.substr(idx - i, N - idx));
		}
	}
	return XOR(S, S.substr(pos, N - idx));
}

int main() {
	int T, N;
	string S;
	nextInt(T);
	while (T--) {
		nextInt(N);
		nextStr(S);
		cout << func(N, S) << "\n";
	}
}
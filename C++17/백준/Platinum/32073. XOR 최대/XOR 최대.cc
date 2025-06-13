#include<iostream>
#include<string>

using namespace std;

string XOR(string s1, string s2) {
	s2 = string(s1.size() - s2.size(), '0') + s2;
	for (int i = 0; i < s1.size(); i++) {
		s1[i] = (s1[i] != s2[i] ? '1' : '0');
	}
	int x = s1.find('1');
	return s1.substr(x);
}

string func(int N, string S) {
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
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T, N;
	string S;
	cin >> T;
	while (T--) {
		cin >> N >> S;
		cout << func(N, S) << "\n";
	}
}
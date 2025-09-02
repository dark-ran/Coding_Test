#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	string S, T;
	cin >> S >> T;
	int s = 0, e = T.size() - 1;
	bool r = true;
	while (S.size() <= e - s) {
		if (r)
			while (T[e] == 'A' && S.size() <= e - s)
				e--;
		else
			while (T[s] == 'A' && S.size() <= e - s)
				s++;

		while (true) {
			if (r && T[e] == 'B' && S.size() <= e - s) {
				r = false;
				e--;
			}
			else if (!r && T[s] == 'B' && S.size() <= e - s) {
				r = true;
				s++;
			}
			else
				break;
		}
	}
	if (r) {
		for (int i = 0;i < S.size();i++) {
			if (S[i] != T[s + i]) {
				cout << 0;
				return 0;
			}
		}
	}
	else {
		for (int i = 0;i < S.size();i++) {
			if (S[i] != T[e - i]) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}
#include<iostream>

using namespace std;

int str[14];
int comb[8];
int k;

void func(int idx, int depth) {
	if (idx == 6) {
		for (int i = 0; i < 6; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (depth == k) return;
	comb[idx] = str[depth];
	func(idx + 1, depth + 1);
	func(idx, depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (cin >> k) {
		if (k == 0)
			return 0;
		for (int i = 0; i < k; i++) {
			cin >> str[i];
		}	
		func(0, 0);
		cout << "\n";
	}
}
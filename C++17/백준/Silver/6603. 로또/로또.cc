#include<iostream>

using namespace std;

int str[13];
int comb[6];
int k;

void func(int idx, int depth) {
	if (idx == 6) {
		for (int i = 0; i < 6; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = depth; i < k; i++) { // 알아서 오름차순으로 정렬되어 입력되기에 들어 올 수 있는 값들은 현재 깊이 이후의 값들만 ㄱㄴ
		comb[idx] = str[i];
		func(idx + 1, i + 1);
	}
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
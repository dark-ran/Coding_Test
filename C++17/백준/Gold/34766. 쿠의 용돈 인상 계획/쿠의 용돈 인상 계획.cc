#include<iostream>

using namespace std;

string mid;

void makestring(int n, int k) {
	if (k == 0)
		mid += string(1, char('0' + n));
	else if (n == 1)
		makestring(9, k - 1);
	else if (n == 9) {
		makestring(8, k - 1);
		mid += "1";
	}
	else {
		mid += string(1, char('0' + n - 1));
		makestring(10 - n, k - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T, D, K;
	string N;
	cin >> T;
	while (T--) {
		cin >> D >> K >> N;
		mid = "";
		int idx = -1;
		for (int i = N.size() - 1;i >= 0;i--) {
			if (N[i] > '1') { //가장 오른쪽 2이상인 위치 찾기
				idx = i;
				break;
			}
		}
		
		if (idx != -1) {
			int d = N[idx] - '0';
			makestring(d, K);
			cout << N.substr(0, idx) << mid << N.substr(idx + 1) << "\n";
		}
		else { //전부 0과1이면
			for (int i = 0;i < N.size();i++) {
				if (N[i] == '1') { //가장 왼쪽 1 찾기
					idx = i;
					break;
				}
			}
			
			makestring(1, K);
			cout << N.substr(0, idx) << mid << N.substr(idx + 1) << "\n";
		}
	}
}
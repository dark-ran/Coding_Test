#include<iostream>

using namespace std;

int arr[128][128];
int white = 0; // 0
int blue = 0;// 1

void check(int x, int y, int r) {
	int num = arr[x][y];
	bool flag = false;
	for (int i = x;i < x + r;i++) {
		for (int j = y;j < y + r;j++) {
			if (arr[i][j] != num) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	if (flag) {
		int m = r >> 1;
		check(x, y, m);
		check(x, y + m, m);
		check(x + m, y, m);
		check(x + m, y + m, m);
	}
	else {
		switch (num) {
		case 0:
			white++;
			break;
		case 1:
			blue++;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> arr[i][j];

	check(0, 0, N);
	cout << white << "\n" << blue;
}
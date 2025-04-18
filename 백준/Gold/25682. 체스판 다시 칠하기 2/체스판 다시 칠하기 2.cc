#include<iostream>

using namespace std;
string board[2002];
int arr[2002][2002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i + 1][j + 1] = arr[i + 1][j] + arr[i][j + 1] - arr[i][j];
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				if (board[i][j] != 'B') arr[i+1][j+1]++;
			}
			else {
				if (board[i][j] != 'W') arr[i + 1][j + 1]++;
			}
		}
	}
	int cnt = k * k;
	for (int i = 0; i < n - k + 1; i++) {
		for (int j = 0; j < m - k + 1; j++) {
			int sum = arr[i + k][j + k] - arr[i][j + k] - arr[i + k][j] + arr[i][j];
			if (k * k < sum * 2) sum = k * k - sum;
			cnt = cnt > sum ? sum : cnt;
		}
	}
	cout << cnt;
}
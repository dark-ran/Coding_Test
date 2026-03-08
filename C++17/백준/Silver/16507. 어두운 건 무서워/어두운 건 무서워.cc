#include<iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int arr[1001][1001] = { 0, };
	int R, C, Q;
	cin >> R >> C >> Q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	int r1, r2, c1, c2;
	while (Q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		int a = arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1];
		int b = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << a / b << "\n";
	}
}
#include<iostream>

using namespace std;

int arr[1026][1026];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, tot, id;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		tot = 0;
		for (int j = 1;j <= n;j++) {
			cin >> id;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] + id - arr[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0;i < m;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << "\n";
	}
}
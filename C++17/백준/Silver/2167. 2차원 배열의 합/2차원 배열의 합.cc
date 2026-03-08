#include <iostream>

using namespace std;
long long arr[301][301];

int main() {
	int n, m;
	int i, j, x, y, k,sum;
	cin >> n >> m;
	
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			cin >> arr[a][b];
		}
	}
	cin >> k;
	for (int c = 1; c <= k; c++) {
		sum = 0;
		cin >> i >> j >> x >> y;
		for (int d = i; d <= x; d++) {
			for (int e = j; e <= y; e++) {
				sum += arr[d-1][e-1];
			}
		}
		cout << sum << endl;
	}
}

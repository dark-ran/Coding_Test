#include<iostream>

using namespace std;
int arr[12];
int n, a, b, c, d;
int mi = 1000000009;
int ma = -1000000009;
void bfs(const int&plu, const int&min, const int&mul, const int&div, const int&idx,const int&tot) {
	if (idx == n) {
		if (tot > ma) ma = tot;
		if (tot < mi) mi = tot;
		return;
	}
	if (plu != a) bfs(plu + 1, min, mul, div, idx + 1, tot + arr[idx]);
	if (min != b) bfs(plu, min + 1, mul, div, idx + 1, tot - arr[idx]);
	if (mul != c) bfs(plu, min, mul + 1, div, idx + 1, tot * arr[idx]);
	if (div != d) bfs(plu, min, mul, div + 1, idx + 1, tot / arr[idx]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> a >> b >> c >> d;
	bfs(0, 0, 0, 0, 1, arr[0]);
	cout << ma << "\n" << mi;
}
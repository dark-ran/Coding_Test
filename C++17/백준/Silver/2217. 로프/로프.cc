#include<iostream>
#include<algorithm>
using namespace std;
int dis[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, cnt;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> dis[i];
	sort(dis, dis + n);
	cnt = dis[0] * n;
	for (int i = 1; i < n; i++) {
		cnt = cnt > dis[i] * (n - i) ? cnt : dis[i] * (n - i);
	}
	cout << cnt;
}
#include<iostream>
using namespace std;
int dis[1000002]{ 0,0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dis[i] = dis[i - 1] + 1;
		if (i % 2 == 0) dis[i] = min(dis[i], dis[i / 2] + 1);
		if (i % 3 == 0) dis[i] = min(dis[i], dis[i / 3] + 1);
	}
	cout << dis[n];
}
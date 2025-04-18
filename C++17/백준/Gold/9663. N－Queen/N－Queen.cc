#include<iostream>
using namespace std;

int dis[16];
int n, cnt = 0;

bool check_queen(int idx) {
	for (int i = 0; i < idx; i++) {
		if (dis[i] == dis[idx] || dis[i] - dis[idx] == i - idx || dis[i] - dis[idx] == idx - i)
			return false;
	}
	return true;
}

void func(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		dis[idx] = i;
		if(check_queen(idx)) func(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	func(0);
	cout << cnt;
}
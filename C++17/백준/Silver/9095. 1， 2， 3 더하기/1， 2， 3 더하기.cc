#include<iostream>
using namespace std;
int dis[12];
int main() {
	int t, n;
	cin >> t;
	dis[1] = 1;
	dis[2] = 2;
	dis[3] = 4;
	for (int i = 4; i < 11; i++)
		dis[i] = dis[i - 3] + dis[i - 2] + dis[i - 1];
	while (t--) {
		cin >> n;
		cout << dis[n] << "\n";
	}
}
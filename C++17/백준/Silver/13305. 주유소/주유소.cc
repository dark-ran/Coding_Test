#include<iostream>

using namespace std;

typedef long long ll;
ll dist[100000];
ll cost[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	int n;
	cin >> n;
	for (int i = 0;i < n - 1;i++)
		cin >> dist[i];
	for (int i = 0;i < n;i++)
		cin >> cost[i];
	ll tot = 0;
	for (int i = 0;i < n - 1;i++) {
		if (cost[i] < cost[i + 1])
			cost[i + 1] = cost[i];
		tot += cost[i] * dist[i];
	}
	cout << tot;
}
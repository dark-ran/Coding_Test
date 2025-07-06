#include<iostream>
#include<vector>

using namespace std;

int v[20];
int res, N;
void bfs(int idx , int num) {
	if (idx == N) {
		res = res < abs(num) ? res : abs(num);
		return;
	}

	bfs(idx + 1, num - v[idx]);
	bfs(idx + 1, num);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int x, sum = 0;
	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> x;
			sum += x;
			v[i] += x;
			v[j] += x;
		}

	res = 1987654321;
	bfs(0, sum);
	cout << res;
}
#include<iostream>

using namespace std;

int arr[701][701];
int N, M;

void func1(int dx,int dy,int x, int y, int z) {
	if (x) x--;
	else if (y) arr[dx][dy]++, y--;
	else if (z) arr[dx][dy] += 2, z--;
	if (dx == 0) {
		if (dy == M - 1) 
			return;
		else
			return func1(dx, dy + 1, x, y, z);
	}
	else
		return func1(dx - 1, dy, x, y, z);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		arr[i][0] = 1;
		arr[0][i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		func1(M - 1, 0, x, y, z);
	}
	
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			arr[i][j] = arr[i - 1][j];
		}
	}
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
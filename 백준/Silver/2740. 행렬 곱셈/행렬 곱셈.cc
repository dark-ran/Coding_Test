#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>A;
vector<vector<int>>B;
int N, M, K, x;

int calc(int i, int j) {
	int sum = 0;
	for (int m = 0; m < M; m++) {
		sum += A[i][m] * B[m][j];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	A.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	cin >> M >> K;
	B.resize(M, vector<int>(K));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << calc(i, j) << " ";
		}
		cout << "\n";
	}
}
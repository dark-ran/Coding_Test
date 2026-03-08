#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int arr[2002][2002];
int main() {
	int n, m, k;
	char c;
	scanf("%d%d%d", &n, &m, &k);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &c);
			arr[i + 1][j + 1] = arr[i + 1][j] + arr[i][j + 1] - arr[i][j];
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
				if (c != 'B') arr[i+1][j+1]++;
			}
			else {
				if (c != 'W') arr[i + 1][j + 1]++;
			}
		}
		getchar();
	}
	int cnt = k * k;
	for (int i = 0; i < n - k + 1; i++) {
		for (int j = 0; j < m - k + 1; j++) {
			int sum = arr[i + k][j + k] - arr[i][j + k] - arr[i + k][j] + arr[i][j];
			if (k * k < sum * 2) sum = k * k - sum;
			cnt = cnt > sum ? sum : cnt;
		}
	}
	printf("%d", cnt);
}
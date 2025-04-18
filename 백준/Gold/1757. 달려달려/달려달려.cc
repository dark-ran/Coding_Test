#include<stdio.h>
#define max(x, y) (x) > (y) ? (x) : (y)

int dp[10001]; //지침지수가 0인 것만 저장
int a[10000];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < N; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		for (int j = 0, p = 0; j < M;) {
			p += a[i + j];
			if (i + ++j * 2 > N) break; //시간초과하면
			dp[i + j * 2] = max(dp[i + j * 2], dp[i] + p); //j번 더 달렸을때 최대
		}
	}
	printf("%d", dp[N]);
}
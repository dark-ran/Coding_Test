#include <algorithm>
#include <stdio.h>

using namespace std;

const int MAX = 101;
const int INF = 12345678;
int D[MAX][MAX];
int arr[MAX];

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            D[i][j] = INF;
    for (int i = 0;i < m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        D[a][b] = 1;
        D[b][a] = 1;
    }
    for (int K = 1;K <= n;K++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++) 
                D[i][j] = min(D[i][j], D[i][K] + D[K][j]);
    for (int K = 1;K <= n;K++) {
        for (int i = 1;i <= n;i++)
            arr[K] += D[K][i];
        arr[K] -= D[K][K];
    }
    int min = arr[1];
    int index = 1;
    for (int i = 2;i <= n;i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    printf("%d", index);
}
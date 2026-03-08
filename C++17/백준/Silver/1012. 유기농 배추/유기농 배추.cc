#include <iostream>

using namespace std;

bool arr[50][50];

void dfs(int row, int col)
{

    if (row < 0 || row >= 50) return;
    if (col < 0 || col >= 50) return;

    if (!arr[row][col])
    {
        return;
    }

    arr[row][col] = false;
    dfs(row + 1, col); // 상
    dfs(row - 1, col); // 하
    dfs(row, col - 1); // 좌
    dfs(row, col + 1); // 우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        int m, n, k;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = true;
        }

        int tot = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (arr[row][col]){
                    tot++;
                    dfs(row, col);
                }
            }
        }

        cout << tot << '\n';
    }
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
int graph[MAX][MAX];
int result[MAX][MAX];
bool visited[MAX][MAX];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int n, m;
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    result[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> cur_pair = q.front();
        for (int v = 0; v < 4; v++)
        {
            int x_next = cur_pair.first + x_move[v];
            int y_next = cur_pair.second + y_move[v];

            if (x_next < 0 || x_next >= n || y_next < 0 || y_next >= m)
                continue;

            if (graph[x_next][y_next] == 1 && !visited[x_next][y_next])
            {
                q.push({ x_next, y_next });
                visited[x_next][y_next] = true;
                result[x_next][y_next] = result[cur_pair.first][cur_pair.second] + 1;
            }
        }
        q.pop();
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    cin >> n >> m;

    int a, x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            graph[i][j] = a;

            if (a == 2)
            {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (result[i][j] == 0 && graph[i][j] == 1)
                cout << -1 << ' ';
            else
                cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
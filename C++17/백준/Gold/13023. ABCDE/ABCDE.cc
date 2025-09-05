#include <iostream>
#include <vector>
#define MAX_N 10000
#define endl "\n"
using namespace std;

bool visited[MAX_N];
vector<int> adjacent[MAX_N];
bool arrive = false;

void dfs(int start, int depth) {
    visited[start] = true;
    if (depth == 5)
    {
        arrive = true;
        return;
    }

    for (int i : adjacent[start])
    {
        if (!visited[i])
        {
            dfs(i, depth + 1);
        }

    }
    visited[start] = false;
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 1);
        if (arrive) {
            break;
        }
    }

    if (arrive)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
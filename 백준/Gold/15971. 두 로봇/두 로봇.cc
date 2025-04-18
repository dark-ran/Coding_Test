#include <iostream>
#include <vector>

using namespace std;

int n, a, b;
bool arr[100001];
bool flag = false;
vector<pair<int, int>>v[100001];


void dfs(int x, int sum, int max_) {
    if (flag)return;
    if (x == b) {
        cout << sum - max_;
        flag = true;
        return;
    }
    for (int i = 0; i < v[x].size(); i++) {
        int nx = v[x][i].first;
        int ny = v[x][i].second;
        if (!arr[nx]) {
            arr[nx] = true;
            dfs(nx, sum + ny, max(ny, max_));
        }
    }
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n-1; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        v[x].push_back({ y,l });
        v[y].push_back({ x,l });
    }
    arr[a] = true;
    dfs(a, 0, 0);
}
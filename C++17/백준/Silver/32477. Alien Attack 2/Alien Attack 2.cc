#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> size_;

int find(int u) {
    if (parent[u] != u) {
        return parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (size_[rootU] < size_[rootV]) {
            swap(rootU, rootV);
        }
        parent[rootV] = rootU;
        size_[rootU] += size_[rootV];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    size_.resize(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    int max_size = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == i) {
            if (size_[i] > max_size) {
                max_size = size_[i];
            }
        }
    }

    cout << max_size << flush;
}
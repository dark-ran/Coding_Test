#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 20001;

class BipartiteGraph {
private:
    vector<int> graph[MAX_V];
    int colors[MAX_V];

public:
    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int K;
        cin >> K;

        while (K--) {
            int V, E;
            cin >> V >> E;

            for (int i = 1; i <= V; i++) {
                graph[i].clear();
                colors[i] = 0;
            }

            for (int i = 0; i < E; i++) {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            bool isBipartite = true;

            for (int i = 1; i <= V && isBipartite; i++) {
                if (colors[i] == 0) {
                    queue<int> q;
                    q.push(i);
                    colors[i] = 1;

                    while (!q.empty() && isBipartite) {
                        int current = q.front();
                        q.pop();

                        for (int neighbor : graph[current]) {
                            if (colors[neighbor] == 0) {
                                colors[neighbor] = -colors[current];
                                q.push(neighbor);
                            }
                            else if (colors[neighbor] == colors[current]) {
                                isBipartite = false;
                                break;
                            }
                        }
                    }
                }
            }

            cout << (isBipartite ? "YES" : "NO") << "\n";
        }
    }
};

int main() {
    BipartiteGraph solver;
    solver.solve();
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Point {
    int x, y, time;
};

int N, M;
int lab[50][50];
vector<Point> viruses;
int emptyCount = 0;
int minTime = INT_MAX;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int simulateBMSSP(vector<int>& selectedIndices) {
    queue<Point> q;
    int visited[50][50] = { 0, };
    int infected = 0;
    int maxTime = 0;

    for (int idx : selectedIndices) {
        Point virus = viruses[idx];
        q.push({ virus.x, virus.y, 0 });
        visited[virus.x][virus.y] = 1;
    }

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (lab[current.x][current.y] == 0) {
            infected++;
            maxTime = max(maxTime, current.time);
        }

        if (infected == emptyCount) {
            return maxTime;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (lab[nx][ny] == 1 || visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({ nx, ny, current.time + 1 });
        }
    }
    return INT_MAX;
}

void generateCombinations() {
    int virusCount = viruses.size();

    vector<int> indices;
    for (int i = 0; i < virusCount; i++) {
        indices.push_back(i);
    }

    vector<bool> mask(virusCount, false);
    fill(mask.end() - M, mask.end(), true);

    do {
        vector<int> selected;
        for (int i = 0; i < virusCount; i++) {
            if (mask[i]) {
                selected.push_back(i);
            }
        }

        int time = simulateBMSSP(selected);
        minTime = min(minTime, time);

    } while (next_permutation(mask.begin(), mask.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 2) {
                viruses.push_back({ i, j });
            }
            else if (lab[i][j] == 0) {
                emptyCount++;
            }
        }
    }

    if (emptyCount == 0) {
        cout << 0 << "\n";
        return 0;
    }

    generateCombinations();

    if (minTime == INT_MAX) {
        cout << -1 << "\n";
    }
    else {
        cout << minTime << "\n";
    }
}
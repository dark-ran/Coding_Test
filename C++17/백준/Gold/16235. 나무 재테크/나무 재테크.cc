#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

const int MAX = 10;
int arr[MAX][MAX];
int soil[MAX][MAX];
deque<int>trees[MAX][MAX];

int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };

struct s {
    int age, x, y;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            soil[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        trees[x-1][y-1].push_back(a);
    }

    for (int year = 0; year < K; year++) {
        vector<s>dead;
        vector<s>breed;
        // Spring
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (trees[i][j].size() == 0) continue;

                sort(trees[i][j].begin(), trees[i][j].end());
                int size = trees[i][j].size();

                for (int k = 0; k < size; k++) {
                    int a = trees[i][j].front();
                    trees[i][j].pop_front();
                    if (soil[i][j] >= a) {
                        soil[i][j] -= a;
                        a++;
                        trees[i][j].push_back(a);
                        if (a % 5 == 0)
                            breed.push_back({ a,i,j });
                    }
                    else
                        dead.push_back({ a,i,j });
                }
            }
        }

        // Summer
        for (auto& tree : dead) {
            soil[tree.x][tree.y] += (tree.age >> 1);
        }

        // Autumn
        for (auto& tree : breed) {
            for (int i = 0; i < 8; i++) {
                int nx = tree.x + dx[i];
                int ny = tree.y + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    trees[nx][ny].push_back(1);
                }
            }
        }

        // Winter
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                soil[i][j] += arr[i][j];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += trees[i][j].size();
        }
    }
    cout << res;
}
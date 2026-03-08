#include <iostream>
using namespace std;

int block[501][501];

int main() {
    int n, m, b, max_ = 0;
    int result_height = 0, result_time = 2 * 500 * 500 * 256;

    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> block[i][j]; 
            max_ = max(max_, block[i][j]);
        }
    }
    
    for (int height = 0; height <= 256; height++) {
        int time = 0, blocks_used = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //쌓여있는 블럭의 높이가 height보다 높다면
                if (block[i][j] > height) {
                    time += (2 * (block[i][j] - height));
                    blocks_used += (height - block[i][j]);
                }
                //
                else {
                    time += (height - block[i][j]);
                    blocks_used += (height - block[i][j]);
                }
            }
        }
        if (blocks_used <= b && time <= result_time) {
            result_time = time;
            result_height = height;
        }
    }
    cout << result_time << " " << result_height << endl;
}

#include <vector>
#include <string>

bool reversal(int N, int M, std::vector<std::string> P) {
    for (int i = 0; i < N; i++) {
        int im = i % M;
        for (int j = 0; j < N; j++) {
            int jm = j % M;
            int need = (P[i][jm] == 'O') ^ (P[im][j] == 'O') ^ (P[im][jm] == 'O');
            if ((P[i][j] == 'O') != need) return false;
        }
    }
    return true;
}

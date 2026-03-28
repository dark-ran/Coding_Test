#include <vector>
#include <string>

bool reversal(int N, int M, std::vector<std::string> P) {
    auto val = [&](int i, int j) -> int {
        return P[i][j] == 'O';
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int need = val(i, j % M) ^ val(i % M, j) ^ val(i % M, j % M);
            if (val(i, j) != need) return false;
        }
    }
    return true;
}

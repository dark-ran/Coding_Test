#include<iostream>
using namespace std;

string input[9];

bool func(int x, int y) {
    if (x == 9) return true;

    if (input[x][y] != '0') {
        if (y < 8) return func(x, y + 1);
        else return func(x + 1, 0);
    }

    for (int num = 1; num <= 9; num++) {
        char candidate = num + '0';
        bool flag = true;

        for (int j = 0; j < 9; j++) {
            if (input[x][j] == candidate || input[j][y] == candidate) {
                flag = false;
                break;
            }
        }

        if (!flag) continue;

        int boxX = x / 3 * 3;
        int boxY = y / 3 * 3;
        for (int dx = 0; dx < 3 && flag; dx++) {
            for (int dy = 0; dy < 3 && flag; dy++) {
                if (input[boxX + dx][boxY + dy] == candidate) {
                    flag = false;
                    break;
                }
            }
        }

        if (!flag) continue;

        input[x][y] = candidate;

        if (y < 8) {
            if (func(x, y + 1)) return true;
        }
        else {
            if (func(x + 1, 0)) return true;
        }

        input[x][y] = '0';
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for (int i = 0; i < 9; i++)
        cin >> input[i];
    func(0, 0);
    for (int i = 0; i < 9; i++)
        cout << input[i] << "\n";
}
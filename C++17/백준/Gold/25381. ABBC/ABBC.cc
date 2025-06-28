#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string& s, bool AB_first) {
    vector<int> A, B, C;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') A.push_back(i);
        else if (s[i] == 'B') B.push_back(i);
        else if (s[i] == 'C') C.push_back(i);
    }

    int res = 0;
    if (AB_first) {
        int a = 0, b = 0;
        while (a < A.size() && b < B.size()) {
            if (A[a] < B[b]) {
                res++;
                a++;
                b++;
            }
            else {
                b++;
            }
        }

        b = 0;
        int c = 0;
        while (b < B.size() && c < C.size()) {
            if (B[b] < C[c]) {
                res++;
                b++;
                c++;
            }
            else {
                c++;
            }
        }
    }
    else {
        int b = 0, c = 0;
        while (b < B.size() && c < C.size()) {
            if (B[b] < C[c]) {
                res++;
                b++;
                c++;
            }
            else {
                c++;
            }
        }

        b = 0;
        int a = 0;
        while (a < A.size() && b < B.size()) {
            if (A[a] < B[b]) {
                res++;
                a++;
                b++;
            }
            else {
                b++;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int ans = max(solve(s, true), solve(s, false));
    cout << ans << flush;

}
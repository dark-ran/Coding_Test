#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int a[2001];
int b[2001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string S, A, B;
    cin >> S >> A >> B;
    set<string> s;
    int A_size = A.size();
    int B_size = B.size();
    int S_size = S.size();

    a[0] = 0;
    for (int i = 1, j = 0; i < A_size; ++i) {
        while (j > 0 && A[i] != A[j]) j = a[j - 1];
        if (A[i] == A[j]) a[i] = ++j;
        else a[i] = 0;
    }

    b[0] = 0;
    for (int i = 1, j = 0; i < B_size; ++i) {
        while (j > 0 && B[i] != B[j]) j = b[j - 1];
        if (B[i] == B[j]) b[i] = ++j;
        else b[i] = 0;
    }

    vector<int> A_start, B_start;

    for (int i = 0, j = 0; i < S_size; ++i) {
        while (j > 0 && S[i] != A[j]) j = a[j - 1];
        if (S[i] == A[j]) ++j;
        if (j == A_size) {
            A_start.push_back(i - A_size + 1);
            j = a[j - 1];
        }
    }

    for (int i = 0, j = 0; i < S_size; ++i) {
        while (j > 0 && S[i] != B[j]) j = b[j - 1];
        if (S[i] == B[j]) ++j;
        if (j == B_size) {
            B_start.push_back(i - B_size + 1);
            j = b[j - 1];
        }
    }

    sort(B_start.begin(), B_start.end());

    for (int a_pos : A_start) {
        auto it = lower_bound(B_start.begin(), B_start.end(), a_pos);
        for (; it != B_start.end(); ++it) {
            int b_pos = *it;
            if (a_pos + A_size > b_pos + B_size) continue;
            string sub = S.substr(a_pos, b_pos + B_size - a_pos);
            s.insert(sub);
        }
    }

    cout << s.size() << flush;
}
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int sqrtN;
int A[100000];
int res[100000];


struct QueryNode {
    int s, e, n;
    QueryNode() : QueryNode(0, 0, -1) {}
    QueryNode(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
    bool operator <(const QueryNode& O)const {
        if (s / sqrtN != O.s / sqrtN) return (s / sqrtN < O.s / sqrtN);
        return (e < O.e);
    }
};

QueryNode Q[100000];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sqrtN = sqrt(N);

    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        Q[i] = QueryNode(l - 1, r, i);
    }
    sort(Q, Q + M);

    long long sum = 0;
    int s = Q[0].s, e = Q[0].e;
    for (int i = s; i < e; ++i)
        sum += A[i];
    res[Q[0].n] = sum;

    for (int i = 1; i < M; ++i) {
        while (Q[i].s < s) sum += A[--s];
        while (e < Q[i].e) sum += A[e++];
        while (Q[i].s > s) sum -= A[s++];
        while (e > Q[i].e) sum -= A[--e];
        res[Q[i].n] = sum;
    }

    for (int i = 0; i < M; ++i)
        cout << res[i] << "\n";
}
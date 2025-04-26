#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int read() {
    int n = 0;
    char c;
    while ((c = getchar()) < '0');
    do {
        n = (n << 3) + (n << 1) + (c - '0');
    } while ((c = getchar()) >= '0');
    return n;
}

int len[1000001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n = read();
    long long ans = 0;
    set<int> tree;
    
    for (int i = 0; i < n; i++) {
        int num = read();
        auto higher = tree.upper_bound(num);
        auto lower = tree.lower_bound(num);
        
        if (lower != tree.begin()) {
            lower--;
        } else {
            lower = tree.end();
        }
        
        if (higher == tree.end()) {
            if (lower == tree.end()) {
                len[num] = 1;
            } else {
                len[num] = len[*lower] + 1;
            }
        } else {
            if (lower == tree.end()) {
                len[num] = len[*higher] + 1;
            } else {
                len[num] = max(len[*higher], len[*lower]) + 1;
            }
        }
        ans += len[num];
        tree.insert(num);
    }
    cout << ans;
}
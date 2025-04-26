#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    set<int> tree;
    map<int, int> depth;

    long long total = 0;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (tree.empty()) {
            tree.insert(num);
            depth[num] = 1;
            total += 1;
            continue;
        }

        auto it = tree.lower_bound(num);
        int current_depth = 0;

        if (it == tree.begin()) {
            current_depth = depth[*it] + 1;
        } else if (it == tree.end()) {
            current_depth = depth[*prev(it)] + 1;
        } else {
            int left_depth = depth[*prev(it)];
            int right_depth = depth[*it];
            current_depth = max(left_depth, right_depth) + 1;
        }
        tree.insert(num);
        depth[num] = current_depth;
        total += current_depth;
    }
    cout << total;
}
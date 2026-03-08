#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, result = 0;
    cin >> a >> b;

    vector<int> v_a(a), v_b(b);

    for (int i = 0; i < a; ++i) {
        cin >> v_a[i];
    }

    for (int i = 0; i < b; ++i) {
        cin >> v_b[i];
    }

    sort(v_a.begin(), v_a.end());
    sort(v_b.begin(), v_b.end());
    int idx_a = 0, idx_b = 0;

    while (idx_a < a && idx_b < b) {
        if (v_a[idx_a] < v_b[idx_b]) {
            idx_a++;
            result++;
        }
        else if (v_a[idx_a] > v_b[idx_b]) {
            idx_b++;
            result++;
        }
        else { //값이 같을 때
            idx_a++;
            idx_b++;
        }
    }
    result += (b - idx_b) + (a - idx_a); //남은 개수 더하기
    cout << result;
}

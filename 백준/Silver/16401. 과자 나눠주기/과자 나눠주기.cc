#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    arr.resize(n);
    for (int& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    int st = 1, ed = arr[n - 1];
    int mid, result = 0;
    while (st <= ed) {
        mid = (st + ed) / 2;
        int cnt = 0;
        for (int i : arr) cnt += i / mid;
        if (m <= cnt) {
            st = mid + 1;
            result = mid;
        }
        else {
            ed = mid - 1;
        }
    }
    cout << result;
}
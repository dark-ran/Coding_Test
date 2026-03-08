#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    arr.resize(n);
    for (int& x : arr) scanf("%d", &x);
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
    printf("%d", result);
}
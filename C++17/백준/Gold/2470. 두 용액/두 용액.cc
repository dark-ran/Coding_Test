#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int N;
    cin >> N;

    int start = 0, end = N - 1, min = 2000000001;
    vector<int> ans(2);
    vector<int>arr(N);

    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    while (start < end) {
        int sum = arr[start] + arr[end];

        if (abs(sum) < min) {
            ans[0] = arr[start];
            ans[1] = arr[end];
            min = abs(sum);
        }

        if (sum < 0) start++;
        else end--;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
}
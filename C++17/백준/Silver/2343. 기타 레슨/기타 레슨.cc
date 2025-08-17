#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, input;
    cin >> n >> m;

    vector<int> blue;

    for (int i = 0; i < n; i++) {
        cin >> input;
        blue.push_back(input);
    }

    int low = 1;
    int high = 1000000000;

    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;


        int cnt = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (mid < blue[i]) {
                cnt = m + 1;
                break;
            }
            if (sum + blue[i] <= mid) {
                sum += blue[i];
            }
            else {
                sum = blue[i];
                cnt++;
            }
        }

        if (cnt <= m) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << result;
}
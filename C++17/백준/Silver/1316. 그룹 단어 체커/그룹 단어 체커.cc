#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, sum;
    string arr1;
    cin >> n;
    sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr1;
        bool arr2[128] = { false };

        for (int j = 0; j < arr1.size(); j++) {
            if (j > 0 && arr1[j] == arr1[j - 1]) {
                continue;
            }

            if (arr2[arr1[j]]) {
                sum++;
                break;
            }
            else {
                arr2[arr1[j]] = true;
            }
        }
    }

    cout << n - sum << endl;
}
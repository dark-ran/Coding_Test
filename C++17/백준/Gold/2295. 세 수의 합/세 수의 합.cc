#include <bits/stdc++.h>

using namespace std;

int a[1005];
int n;
vector<int> two;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            two.push_back(a[i] + a[j]);
        }
    }

    sort(a, a + n);
    sort(two.begin(), two.end());

    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            bool check = binary_search(two.begin(), two.end(), a[i] - a[j]);

            if (check){
                cout << a[i];
                return 0;
            }
        }
    }
}
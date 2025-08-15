#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[102][10002];

void compress(int k){
    vector<int> tmp(arr[k], arr[k] + m);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for (int i = 0; i < m; i++)
        arr[k][i] = lower_bound(tmp.begin(), tmp.end(), arr[k][i]) - tmp.begin();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int k = 0; k < n; k++)
        compress(k);

    int ans = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            int flag = true;
            for (int k = 0; k < m; k++){
                if (arr[i][k] != arr[j][k]){
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
    }

    cout << ans;
}
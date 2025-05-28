#include<iostream>
#include<vector>

using namespace std;

int dat[2001][2001];
int arr[2001];
int res[2001];
int n, m;

bool check() {
    for (int i = 0; i < n; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++) {
            if (res[j] != dat[i][j])
                diff++;
            if (diff > 1)
                return false;
        }
        if (diff != 1)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dat[i][j];
        }
    }

    if (n == 1) {
        cout << 0 << " ";
        for (int i = 1; i < m; i++)
            cout << dat[0][i] << " ";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        arr[i] = dat[0][i];
        res[i] = dat[0][i];
    }

    for (int i = 1; i < n; i++) {
        vector<int>index;
        for (int j = 0; j < m; j++) {
            if (arr[j] != dat[i][j])
                index.push_back(j);
        }

        if (index.size() == 2) {
            res[index[0]] = dat[i][index[0]];

            if (!check()) {
                res[index[0]] = arr[index[0]];
                res[index[1]] = dat[i][index[1]];
            }

            for (int i = 0; i < m; i++) {
                cout << res[i] << " ";
            }
            return 0;
        }
    }

    {
        int pos = -1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[j] != dat[i][j])
                {
                    pos = j;
                    break;
                }
            }
            if (pos != -1)
                break;
        }
        if (pos == -1)
            pos = 0;
        res[pos] = 0;
        for (int i = 0; i < m; i++)
            cout << res[i] << " ";
    }
}
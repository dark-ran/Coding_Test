#include <iostream>
#include<unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    string site, pas;
    cin >> n >> m;
    unordered_map<string, string>ma;
    for (int i = 0; i < n; i++) {
        cin >> site >> pas;
        ma.insert({ site,pas });
    }
    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << ma[site] << "\n";
    }
}

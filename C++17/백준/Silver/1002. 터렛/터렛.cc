#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t, x1, y1, r1, x2, y2, r2, res;
    double dis, sub;
    cin >> t;

    while (t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        sub = r1 > r2 ? r1 - r2 : r2 - r1;
        if (dis == 0 && r1 == r2) res = -1;
        else if (dis < r1 + r2 && (sub < dis)) res = 2;
        else if (dis == r1 + r2 || dis == sub) res = 1;
        else res = 0;
        cout << res << "\n";
    }
}
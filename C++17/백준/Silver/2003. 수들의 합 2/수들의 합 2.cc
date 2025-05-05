#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m,count = 0;
    cin >> n >> m;

    int a[n+1];

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    int start=0,end=0;
    int result = a[0];

    while(start<=end && end<n) {
        if(result<m) {
            result+=a[++end];
        } else if(result==m) {
            count++;
            result+=a[++end];
        } else if(result>m) {
            result -=a[start++];

            if(start>end) {
                end = start;
                result = a[start];
            }
        }
    }

    cout << count;
}
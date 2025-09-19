
#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T, Q;
    cin >> T;
    while (T--) {
        cin >> Q;
        priority_queue<int> max;
        priority_queue<int, vector<int>, greater<>> min;
        map<int, int> count;

        while (Q--) {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                max.push(n);
                min.push(n);
                count[n]++;
            }
            else {
                if (count.empty()) continue;

                if (n == 1) {
                    while (!max.empty() && count[max.top()] == 0) {
                        max.pop();
                    }
                    if (!max.empty()) {
                        count[max.top()]--;
                        if (count[max.top()] == 0) {
                            count.erase(max.top());
                        }
                        max.pop();
                    }
                }
                else {
                    while (!min.empty() && count[min.top()] == 0) {
                        min.pop();
                    }
                    if (!min.empty()) {
                        count[min.top()]--;
                        if (count[min.top()] == 0) {
                            count.erase(min.top());
                        }
                        min.pop();
                    }
                }
            }
        }

        while (!max.empty() && count[max.top()] == 0) {
            max.pop();
        }
        while (!min.empty() && count[min.top()] == 0) {
            min.pop();
        }

        if (min.empty() || max.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << max.top() << " " << min.top() << "\n";
        }
    }
}
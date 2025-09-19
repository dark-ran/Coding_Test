#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T, Q;
    cin >> T;
    
    while (T--) {
        cin >> Q;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;
        unordered_map<int, int> valid_count;
        int total_size = 0;

        while (Q--) {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                max_heap.push(n);
                min_heap.push(n);
                valid_count[n]++;
                total_size++;
            }
            else {
                if (total_size == 0) continue;
                
                if (n == 1) {
                    while (!max_heap.empty() && valid_count[max_heap.top()] == 0) {
                        max_heap.pop();
                    }
                    if (!max_heap.empty()) {
                        valid_count[max_heap.top()]--;
                        total_size--;
                        max_heap.pop();
                    }
                }
                else {
                    while (!min_heap.empty() && valid_count[min_heap.top()] == 0) {
                        min_heap.pop();
                    }
                    if (!min_heap.empty()) {
                        valid_count[min_heap.top()]--;
                        total_size--;
                        min_heap.pop();
                    }
                }
            }
        }

        while (!max_heap.empty() && valid_count[max_heap.top()] == 0) {
            max_heap.pop();
        }
        while (!min_heap.empty() && valid_count[min_heap.top()] == 0) {
            min_heap.pop();
        }

        if (min_heap.empty() || max_heap.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }
}
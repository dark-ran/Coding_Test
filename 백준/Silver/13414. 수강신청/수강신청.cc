#include <iostream>
#include <vector>
#include<stack>

using namespace std;
bool check[100000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, l, id;
    cin >> k >> l;
    stack<int>st;
    vector<int>v;
    for (int i = 0; i < l; ++i) {
        cin >> id;
        st.push(id);
    }
    while (!st.empty()) {
        if (!check[st.top()]) {
            check[st.top()] = true;
            v.push_back(st.top());
            st.pop();
        }
        else
            st.pop();
    }

    for (int i = v.size() - 1; i >= 0 && k > 0; i--, k--) {
        cout.width(8);
        cout.fill('0');
        cout << v[i] << "\n";
    }
}
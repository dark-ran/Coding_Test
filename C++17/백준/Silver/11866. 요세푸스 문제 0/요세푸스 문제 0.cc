#include <iostream>
using namespace std;
int arr[10000003];
class queue {
public:
    queue():first(0),last(-1){};
    void push(int x);
    int pop();
    void make_que(int n);
private:
    int first, last;
};

void queue::push(int x) {
    arr[++last] = x;
}
int queue::pop() {
    return arr[first++];
}
void queue::make_que(int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    last = n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    queue q;
    q.make_que(n);
    cout << "<";
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < k - 1; i++)
            q.push(q.pop());
        cout << q.pop();
        if (p == n - 1)
            cout << ">";
        else
            cout << ", ";
    }
}
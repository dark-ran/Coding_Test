#include <iostream>
using namespace std;
char arr[103];

class stack {
public:
    stack() : size(0) {}
    void push(int a);
    int pop();
    bool empty();
    int top();
private:
    int size;
};
void stack::push(int a) {
    arr[size++] = a;
}
int stack::pop() {
    if (size != 0)
        return arr[--size];
    else
        return '0';
}
bool stack::empty() {
    return size == 0;
}
int stack::top() {
    if (size != 0)
        return arr[size - 1];
    else
        return '0';
}

bool isMatching(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int func() {
    char a[103];
    cin.getline(a, 103, '\n');
    if (a[0] == '.')return 2;
    stack s;
    int i = 0;
    if (a[i] == '.')
        return 2;
    while (a[i] != 0) {
        if (a[i] == '(' || a[i] == '[')s.push(a[i]);
        else if (a[i] == ')' || a[i] == ']') {
            if (s.empty() || !isMatching(s.top(), a[i]))
                return 0;
            else
                s.pop();
        }
        i++;
    }
    if (s.empty())
        return 1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        int check = func();
        if (check == 1) cout << "yes\n";
        else if (check == 0)cout << "no\n";
        else break;
    }
}
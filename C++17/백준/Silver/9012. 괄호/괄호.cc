#include<iostream>
using namespace std;
int arr[53];

class stack {
public:
	stack() : size(0) {}
	void push(int a);
	int pop();
	bool empty();
private:
	int size;
};
void stack::push(int a) {
	arr[size++] = a;
}
int stack::pop() {
	return arr[--size];
}
bool stack::empty() {
	return size == 0;
}
void func(string a) {
	bool checked = true;
	stack s;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			s.push('(');
		else if (s.empty()) {
			checked = false;
			break;
		}
		else
			s.pop();
	}
	if (s.empty() && checked)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string a;
	while (n--) {
		cin >> a;
		func(a);
	}
}
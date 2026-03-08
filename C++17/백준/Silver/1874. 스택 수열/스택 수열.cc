#include<iostream>

using namespace std;

int so = 0, b = 0, c = 0, n;
int a[100003];
char sol[10000003];
bool check = true;

class stack {
public:
	stack():size(0) {};
	void push(int x);
	int pop();
	int top();
private:
	int arr[100003] = { 0 };
	int size;
};

void stack::push(int x) {
	arr[size++] = x;
	sol[so++] = '+';
}

int stack::pop() {
	sol[so++] = '-';
	arr[size-1] = 0;
	return arr[--size];
}

int stack::top() {
	return arr[size-1];
}

stack s;

void func() {
	if (c >= n)
		return;
	if (a[c] > s.top()) {
		s.push(++b);
		func();
	}
	else if (a[c] == s.top()) {
		s.pop();
		c++;
		func();
	}
	else {
		check = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	func();
	if (check) {
		for (int i = 0; i < so; i++)
			cout << sol[i]<<"\n";
	}
	else
		cout << "NO";
}
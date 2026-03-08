#include<iostream>
using namespace std;

int arr[1000003];

class queue {
public:
	queue() : front(0), back(0) {}
	void push(int a);
	void pop();
	int result();
	int back;
	int front;
};

void queue::push(int a) {
	arr[++back] = a;
}
void queue::pop() {
	front++;
}
int queue::result() {
	while (true) {
		if (back - front == 0)
			return arr[back];
		pop();
		if (back - front == 0)
			return arr[back];
		push(arr[front]);
		pop();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	queue q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	q.back = n - 1;
	cout<<q.result();
}
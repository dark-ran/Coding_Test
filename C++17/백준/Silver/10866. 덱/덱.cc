#include <iostream>

using namespace std;

//덱(순환큐) 구현
class Deque {
public:
	Deque(int n) {
		first = 0;
		last = 0;
		size = n;
		deque = new int[n] {0}; //동적메모리 할당 그리고 0으로 초기화
	}
	~Deque() {
		delete[]deque;
	}
	void pushfront(int x);
	void pushback(int x);
	void popfront();
	void popback();
	bool isempty();
	int showsize();
	int showfront();
	int showback();
private:
	int first, last, size;
	int* deque = {};
};

void Deque::pushfront(int x) {
	deque[first] = x;
	first = (first - 1 + size) % size;
}
void Deque::pushback(int x) {
	last = (last + 1) % size;
	deque[last] = x;
}
void Deque::popfront() {
	if (isempty())
		cout << -1<<"\n";
	else {
		first = (first + 1) % size;
		cout << deque[first]<<"\n";
		deque[first] = 0;
	}
}

void Deque::popback() {
	if (isempty())
		cout << "-1"<<"\n";
	else {
		cout << deque[last]<<"\n";
		deque[last] = 0;
		last = (last - 1 + size) % size;
	}
}
bool Deque::isempty() {
	if (deque[last] == 0 && deque[(first + 1) % size] == 0)
		return true;
	else
		return false;
}
int Deque::showsize() {
	return first <= last ? last - first : last + size - first;
}
int Deque::showfront() {
	cout << deque[(first + 1) % size]<<"\n";
	return deque[(first + 1) % size];
}
int Deque::showback() {
	cout << deque[last]<<"\n";
	return deque[last];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	string str;
	cin >> n;
	Deque d(n);
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> x;
			d.pushfront(x);
		}

		if (str == "push_back") {
			cin >> x;
			d.pushback(x);
		}

		else if (str == "pop_front")
			d.popfront();

		else if (str == "pop_back")
			d.popback();

		else if (str == "size")
			cout << d.showsize() << "\n";

		else if (str == "empty") {
			if (d.isempty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}

		else if (str == "front") {
			if (d.isempty())
				cout << "-1" << "\n";
			else
				d.showfront();
		}

		else if (str == "back") {
			if (d.isempty())
				cout << "-1" << "\n";
			else
				d.showback();
		}
	}
}
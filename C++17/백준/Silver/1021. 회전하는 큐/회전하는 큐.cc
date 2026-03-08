#include<iostream>
using namespace std;

class Deque {
private:
	int first, last, size;
public:
	int* deque = {};
	Deque(int n) {
		first = 0;
		last = 0;
		size = n+1;
		deque = new int[n+1] {0};
	}
	~Deque() {
		delete[]deque;
	}
	void pushfront(int x);
	void pushback(int x);
	int popfront();
	int popback();
	int showsize();
	int showfront();
	bool match(int i, int a);
};
void Deque::pushfront(int x) {
	deque[first] = x;
	first = (first - 1 + size) % size;
}
void Deque::pushback(int x) {
	last = (last + 1) % size;
	deque[last] = x;
} 
int Deque::popfront() {
	first = (first + 1) % size;
	int a = deque[first];
	deque[first] = 0;
	return a;
}
int Deque::popback() {
	int a = deque[last];
	deque[last] = 0;
	last = (last - 1 + size) % size;
	return a;
}
int Deque::showsize() {
	return first <= last ? last - first : last + size - first;
}
int Deque::showfront() {
	return deque[(first + 1) % size];
}
bool Deque::match(int i, int a) {
	return deque[(i + first + 1) % size] == a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, n, m, i, sol = 0;
	int size;
	cin >> n >> m;
	Deque dq(n);
	for (i = 0; i < n; i++)
		dq.pushback(i + 1);
	while (m--) {
		cin >> a;
		size = dq.showsize();
		for (i = 0; i < size; i++) {
			if (dq.match(i,a)) {
				break;
			}
		}
		if (i <= size / 2) {
			while (dq.showfront() != a) {
				if(dq.showfront()!=0)
					sol++;
				dq.pushback(dq.popfront());
			}
		}
		else {
			while (dq.showfront() != a) {
				if (dq.showfront() != 0)
					sol++;
				dq.pushfront(dq.popback());
			}
		}
		dq.popfront();
	}
	cout << sol;
}
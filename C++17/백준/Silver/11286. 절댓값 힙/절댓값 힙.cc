#include <iostream>
int heap[100003];

using namespace std;
template <typename T>

void swaping(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
int abs(int a) {
	if (a > 0)
		return a;
	else
		return 0 - a;
}

bool com_abs(int a, int b) {
	if (abs(a) < abs(b))
		return true;
	else if (abs(a) > abs(b))
		return false;
	else {
		if (b >= a)
			return true;
		else
			return false;
	}
}


class absheap {
public:
	void insert(int x);
	void remove();
private:
	int cur, heap_num = 0;
	void heapify(int idx);
	void rheapify(int idx);
};

void absheap::insert(int x) {
	heap_num++;
	if (heap_num == 1)
		heap[1] = x;
	else {
		heap[heap_num] = x;
		heapify(heap_num);
	}
}

void absheap::heapify(int idx) {
	if (idx != 1) {
		if (idx % 2 == 0) {
			if (com_abs(heap[idx], heap[idx/2])) {
				swaping(heap[idx / 2], heap[idx]);
				heapify(idx / 2);
			}
		}
		else {
			if (com_abs(heap[idx] , heap[(idx - 1) / 2])) {
				swaping(heap[(idx - 1) / 2], heap[idx]);
				heapify((idx - 1) / 2);
			}
		}
	}
}

void absheap::remove() {
	if (heap_num == 0)
		cout << "0\n";
	else {
		cout << heap[1] << "\n";
		heap[1] = heap[heap_num];
		heap[heap_num] = 0;
		heap_num--;
		rheapify(1);
	}
}

void absheap::rheapify(int idx) {
	if (idx * 2 > heap_num);
	else if (idx * 2 + 1 > heap_num) {
		cur = idx * 2;
		if (com_abs(heap[cur] , heap[idx])) {
			swaping(heap[idx], heap[cur]);
			if (cur <= heap_num)
				rheapify(cur);
		}
	}
	else {
		if (com_abs(heap[idx * 2], heap[idx * 2 + 1]))
			cur = idx * 2;
		else
			cur = idx * 2 + 1;
		if (com_abs(heap[cur], heap[idx])) {
			swaping(heap[idx], heap[cur]);
			if (cur <= heap_num)
				rheapify(cur);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n;
	absheap absheap;
	while (n--) {
		cin >> x;
		if (x == 0)
			absheap.remove();
		else
			absheap.insert(x);
	}
}
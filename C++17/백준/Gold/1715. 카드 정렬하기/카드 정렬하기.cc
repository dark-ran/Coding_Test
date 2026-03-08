#include <iostream>
int heap[100003];

using namespace std;
template <typename T>

void swaping(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

class minheap {
public:
	void insert(int x);
	int remove();
	int length();
private:
	int cur, heap_num = 0;
	void heapify(int idx, int x);
	void rheapify(int idx);
};

void minheap::insert(int x) {
	heap_num++;
	if (heap_num == 1)
		heap[heap_num] = x;
	else {
		heapify(heap_num, x);
	}
}

int minheap::remove() {
	if (heap_num == 0)
		cout << "0\n";
	else {
		int a = heap[1];
		heap[1] = heap[heap_num];
		heap[heap_num] = 0;
		heap_num--;
		rheapify(1);
		return a;
	}
}

void minheap::heapify(int idx, int x) {
	if (idx % 2 == 0) {
		if (heap[idx / 2] > x) {
			heap[idx] = heap[idx / 2];
			idx /= 2;
			heapify(idx, x);
		}
		else {
			heap[idx] = x;
		}
	}
	else {
		if (heap[(idx - 1) / 2] > x) {
			heap[idx] = heap[(idx - 1) / 2];
			idx = (idx - 1) / 2;
			heapify(idx, x);
		}
		else {
			heap[idx] = x;
		}
	}
}

void minheap::rheapify(int idx) {
	if (idx * 2 > heap_num);
	else if (idx * 2 + 1 > heap_num) {
		cur = idx * 2;
		if (heap[idx] > heap[cur]) {
			swaping(heap[idx], heap[cur]);
			idx = cur;
			if (idx <= heap_num)
				rheapify(idx);
		}
	}
	else {
		cur = heap[idx * 2] < heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
		if (heap[idx] > heap[cur]) {
			swaping(heap[idx], heap[cur]);
			idx = cur;
			if (idx <= heap_num)
				rheapify(idx);
		}
	}
}

int minheap::length() {
	return heap_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	int a, b;
	long long ans = 0;
	cin >> n;
	minheap minheap;
	while (n--) {
		cin >> x;
		minheap.insert(x);
	}
	while (minheap.length() > 1) {
		a = minheap.remove();
		b = minheap.remove();
		ans += a + b;
		minheap.insert(a + b);
	}
	cout << ans;
}
#include<iostream>
using namespace std;

char heap[100]{ 0 };
void swaping(char &a,char &b){
	char temp;
	temp = a;
	a = b;
	b = temp;
}
class maxheap {
public:
	maxheap() {
		cur = 0;
		size = 0;
	};
	void push(char x);
	char pop();
private:
	void heapify(int idx);
	void rheapify(int idx);
	int cur;
	int size;
};
void maxheap::push(char x) {
	heap[size] = x;
	if (size != 0)
		heapify(size);
	size++;
}
void maxheap::heapify(int idx) {
	if (idx == 0) return;
	if (idx % 2 == 0) {//오른쪽 자식이라면
		if (heap[(idx / 2) - 1] < heap[idx]) {//현재가 부모보다 값이 클 때
			swaping(heap[(idx / 2) - 1], heap[idx]);
			heapify((idx / 2) - 1);
		}
	}
	else {//왼쪽 자식이라면
		if (heap[(idx - 1) / 2] < heap[idx]) {
			swaping(heap[(idx - 1) / 2], heap[idx]);
			heapify((idx - 1) / 2);
		}
	}
}
char maxheap::pop() {
	if (size == 0) return -1;
	size--;
	char c = heap[0];
	heap[0] = heap[size];
	heap[size] = 0;
	if (size != 0)
		rheapify(0);
	return c;
}
void maxheap::rheapify(int idx) {
	if (2 * idx + 1 > size-1) return; //자식이 없을 때
	else if (2 * idx + 2 > size-1) {//왼쪽 자식만 값이 있을 때
		if (heap[2 * idx + 1] > heap[idx]) {
			swaping(heap[2 * idx + 1], heap[idx]);
			rheapify(2 * idx + 1);
		}
	}
	else {//자식이 다 있을 때
		cur = heap[2 * idx + 1] > heap[2 * idx + 2] ? 2 * idx + 1 : 2 * idx + 2;
		if (heap[cur] > heap[idx]) {
			swaping(heap[cur], heap[idx]);
			rheapify(cur);
		}
	}
}
int main() {
	string n;
	char a;
	cin >> n;
	maxheap heap;
	for (char c : n) {
		heap.push(c);
	}
	while (true) {
		a = heap.pop();
		if (a == -1) break;
		cout << a;
	}
}
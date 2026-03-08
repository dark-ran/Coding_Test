#include <iostream>
int heap[100003];

using namespace std;
template <typename T>

//인수 교환을 편하게 하기 위한 함수
void swaping(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

class maxheap {
public:
	void insert(int x);
	void remove();
private:
	int cur, heap_num = 0;
	void heapify(int idx); //추가할 때 최대힙 유지를 위한 함수
	void rheapify(int idx); //삭제할 때 최대힙 유지를 위한 함수
};

void maxheap::insert(int x) {
	heap_num++;
	//heap안에 어떤한 값도 없으면 heap[1]에 값을 넣어라
	if (heap_num == 1)
		heap[1] = x;
	//heap안에 한 개 이상의 값이 존재한다면 heapify로 넘어가라
	else {
		heap[heap_num] = x;
		heapify(heap_num);
	}
}

void maxheap::heapify(int idx) {
	//현재 위치가 가장 위라면 중단
	if (idx != 1) {
		//현재 위치가 왼쪽 자식이라면
		if (idx % 2 == 0) {
			//부모가 현재 값보다 작다면
			if (heap[idx / 2] < heap[idx]) {
				swaping(heap[idx / 2], heap[idx]);
				heapify(idx / 2);
			}
			//부모가 현재 값보다 크다면 중단
		}
		//현재가 오른쪽 자식이라면
		else {
			//부모가 현재 값보다 작다면
			if (heap[(idx - 1) / 2] < heap[idx]) {
				swaping(heap[(idx - 1) / 2], heap[idx]);
				heapify((idx - 1) / 2);
			}
			//부모가 현재 값보다 크다면 중단
		}
	}
}

void maxheap::remove() {
	//heap안에 어떤 인수도 존재하지 않을 때
	if (heap_num == 0)
		cout << "0\n";
	//heap안에 인수가 존재 할 때
	else {
		//heap[1]값을 heap가장 마지막 값으로 채우기
		cout << heap[1] << "\n";
		heap[1] = heap[heap_num];
		heap[heap_num] = 0;
		heap_num--;
		rheapify(1);
	}
}

void maxheap::rheapify(int idx) {
	//왼쪽 자식의 값이 현재 값보다 작다면
	if (idx * 2 > heap_num);
	else if (idx * 2 + 1 > heap_num) {
		cur = idx * 2;
		//현재 값이 왼쪽 자식의 값보다 작다면
		if (heap[idx] < heap[cur]) {
			swaping(heap[idx], heap[cur]);
			idx = cur;
			if (idx <= heap_num)
				rheapify(idx);
		}
	}
	else {
		cur = heap[idx * 2] > heap[idx * 2 + 1] ? idx * 2 : idx * 2 + 1;
		if (heap[idx] < heap[cur]) {
			swaping(heap[idx], heap[cur]);
			idx = cur;
			if (idx <= heap_num)
				rheapify(idx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n;
	maxheap maxheap;
	while (n--) {
		cin >> x;
		if (x == 0)
			maxheap.remove();
		else
			maxheap.insert(x);
	}
}
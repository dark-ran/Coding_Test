#include<iostream>

using namespace std;
int max_[103] = { 0 };


class queue {
public:
    queue() :first(0), last(-1) {};
    void push(int x);
    int pop();
    int top();
    int first, last;
private:
    int arr[100003] = { 0 };
};

void queue::push(int x) {
    arr[++last] = x;
}
int queue::pop() {
    return arr[first++];
}
int queue::top() {
    return arr[first];
}


//아래는 최대힙

void swaping(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

class maxheap {
public:
	maxheap() :heap_num(0), cur(0) {};
	void insert(int x);
	void remove();
	int front();
	int heap_num;
private:
	int cur;
	void heapify(int idx); //추가할 때 최대힙 유지를 위한 함수
	void rheapify(int idx); //삭제할 때 최대힙 유지를 위한 함수
	int heap[100003] = { 0 };
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
	//heap안에 인수가 존재 할 때
	if(heap_num!=0) {
		//heap[1]값을 heap가장 마지막 값으로 채우기
		heap[1] = heap[heap_num];
		heap[heap_num] = 0;
		heap_num--;
		rheapify(1);
	}
}

void maxheap::rheapify(int idx) {
	//자식이 존재하지 않을 때
	if (idx * 2 > heap_num);
	//왼쪽 자식만 존재할 때
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
	//자식이 다 있을 때
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

int maxheap::front() {
	return heap[1];
}
//여기 위까지 최대힙


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k; //테스트 케이스의 수
	cin >> k;
	while (k--) {
        queue q;
		maxheap maxheap;
		int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            q.push(p);
			maxheap.insert(p);
        }
        int rep = m; //목표값의 위치
        while (true) {
            if (maxheap.front() == q.top()) {
                if (q.first == rep) {
					cout << n - maxheap.heap_num + 1 << "\n";
                    break;
                }
				maxheap.remove();
                q.pop();
            }
            else {
                if (q.first == rep) {
                    q.push(q.pop());
                    rep = q.last;
                }
                else q.push(q.pop());
            }
        }
	}
}

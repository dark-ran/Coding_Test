#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, L, x;
	cin >> N >> L;
	deque<pair<int,int>>dq; //num, idx
	for (int i = 0;i < N;i++) {
		cin >> x;
		while (!dq.empty() && dq.front().second < i - L + 1)dq.pop_front();
		while (!dq.empty() && dq.back().first >= x)dq.pop_back();
		dq.push_back({ x,i });
		cout << dq.front().first << " ";
	}
}
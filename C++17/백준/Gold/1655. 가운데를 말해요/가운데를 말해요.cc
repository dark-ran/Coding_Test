#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>>asc;//right
	priority_queue<int>desc;//left
	int mid, x;
	cin >> mid;
	cout <<mid << "\n";
	for (int i = 1;i < N;i++) {
		cin >> x;
		if (mid <= x)
			asc.push(x);
		else
			desc.push(x);
		if ((i + 1) % 2 == 0) {//짝
			if (desc.size() < asc.size()) {
				cout << mid << "\n";
			}
			else {
				asc.push(mid);
				mid = desc.top();
				desc.pop();
				cout << mid << "\n";
			}
		}
		else {//홀
			if (desc.size() < asc.size()) {
				desc.push(mid);
				mid = asc.top();
				asc.pop();
				cout << mid << "\n";
			}
			else if (desc.size() > asc.size()) {
				asc.push(mid);
				mid = desc.top();
				desc.pop();
				cout << mid << "\n";
			}
			else {
				cout << mid << "\n";
			}
		}
	}
}
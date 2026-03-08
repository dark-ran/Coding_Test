#include <iostream>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int x;
	string str;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop") {
			if (dq.size()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << "-1" << "\n";
			}
		}
		else if (str == "size") {
			cout << dq.size()<<"\n";
		}
		else if (str == "empty") {
			if (dq.size())
				cout << "0" <<"\n";
			else
				cout << "1"<<"\n";
		}
		else if (str == "top") {
			if (dq.size())
				cout << dq.back() << "\n";
			else
				cout << "-1"<<"\n";
		}
	}
}
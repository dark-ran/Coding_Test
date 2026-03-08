#include <iostream>
#include<deque>
using namespace std;

deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") {
			cin >> x;
			dq.push_back(x);
		}

		else if (str == "pop") {
			if (dq.empty())
				cout << "-1" << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}

		else if (str == "size") {
			cout << dq.size() << "\n";
		}

		else if (str == "empty") {
			if (dq.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}

		else if (str == "front") {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.front() << "\n";
		}

		else if (str == "back") {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.back() << "\n";
		}
	}
}
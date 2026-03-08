#include <iostream>
#include<deque>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    deque<int> dq;
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
				cout << dq.back() << "\n";
				dq.pop_back();
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

		else if (str == "top") {
			if (dq.empty())
				cout << "-1" << "\n";
			else
				cout << dq.back() << "\n";
		}
	}
}
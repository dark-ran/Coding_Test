#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	string s;
	cin >> s;
	stack<char>st;
	string res;
	for (int i = 0;i < s.size();i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			cout << s[i];
		}
		else {
			if (s[i] == '(')
				st.push(s[i]);
			else if (s[i] == '*' || s[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
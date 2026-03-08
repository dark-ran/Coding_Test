#include<iostream>

using namespace std;

class Stack {
public:
	Stack()  {
		idx = 0;
	};
	void push(int x);
	int pop();
	int top();
	bool empty();
private:
	int stack[33] = { 0 };
	int idx;
};
void Stack::push(int x) {
	stack[idx++] = x;
}
int Stack::pop() {
	int a = stack[--idx];
	stack[idx] = 0;
	return a;
}
int Stack::top() {
	return stack[idx - 1];
}
bool Stack::empty() {
	if (idx == 0)
		return true;
	else
		return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	cin >> str;
	int temp = 1, answer=0;
	Stack s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				answer = 0;
				break;
			}
			else if (str[i - 1] == '(')
				answer += temp;
			s.pop();
			temp /= 2;
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				answer = 0;
				break;
			}
			else if (str[i - 1] == '[')
				answer += temp;
			s.pop();
			temp /= 3;
		}
	}
	if (s.empty())
		cout << answer;
	else
		cout << 0;
}
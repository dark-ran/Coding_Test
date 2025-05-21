#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

int check(char c) {
	if ('a' <= c && c <= 'z') return 1;
	if (c == '+' || c == '-' || c == '%' || c == '/' || c == '*') return 2;
	if (c == '(') return 3;
	if (c == ')')return 4;
	return -1;
}

int main() {
	char arr[1000]; 
	fgets(arr, sizeof(arr), stdin);

	stack<char>st;
	bool flag = true;
	for (int i = 0;arr[i]!='\n'; i++) {
		int pre = -1;
		if (arr[i] == ' ')continue;
		int cur = check(arr[i]);
		if (cur == -1) {
			printf("error");
			return 0;
		}
		if (st.size()) pre = st.top();

		if (cur == 1) {
			if (pre == 1) {
				printf("error");
				return 0;
			}
			st.push(cur);
		}
		else if (cur == 2) {
			if (pre != 1) {
				printf("error");
				return 0;
			}
			st.push(cur);
		}
		else if (cur == 3) {
			if (pre == 1) {
				printf("error");
				return 0;
			}
			st.push(cur);
		}
		else if (cur == 4) {
			bool word = true;
			bool close = false;
			int cnt = 0;
			while (st.size()) {
				int a = st.top();
				st.pop();
				if (word) {
					if (a == 1) {
						cnt++;
						word = false;
					}
					else {
						printf("error");
						return 0;
					}
				}
				else {
					if (a == 2) {
						word = true;
					}
					else if (a == 3) {
						if (cnt != 2) flag = false;
						close = true;
						break;
					}
				}
			}
			if (!close) {
				printf("error");
				return 0;
			}
			st.push(1);
		}
	}

	bool word = true;
	int cnt = 0;
	while (st.size()) {
		int a = st.top();
		st.pop();
		if (word) {
			if (a == 1) {
				cnt++;
				word = false;
			}
			else {
				printf("error");
				return 0;
			}
		}
		else {
			if (a == 2) word = true;
			else if (a == 3) {
				printf("error");
				return 0;
			}
		}
	}
	if (cnt != 2) flag = false;
	if (flag)
		printf("proper");
	else
		printf("improper");
}
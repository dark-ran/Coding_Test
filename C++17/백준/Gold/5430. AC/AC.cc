#include<iostream>

using namespace std;

int arr[100003] = { 0 };
int cnt = 0, start = 0;

void func(string str) {
	char a[103] = { 0 };
	int stack = 0;
	for (int i = 1; i < str.length(); i++) {
		if (str[i]!=','&&str[i]!=']') {
			a[stack++] = str[i];
		}
		else {
			stack--;
			if (stack < 0)return;
			int cur = 0;
			int s = 1;
			for (int k = stack; k >=0; k--) {
				for (int p = 0; p < k; p++)
					s *= 10;
				cur+=s*(a[stack-k]-48);
				s = 1;
			}
			arr[cnt++] = cur;
			stack = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
    string str, a;
	int p;
    bool temp, cur;
	while (t--) {
		temp = true; //true면 정방향, false면 역방향
		cur = true; //에러 발생하면 false
		cin >> str >> p >> a;
		func(a);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'R') {
				if (temp)
					temp = false;
				else
					temp = true;
			}
			else {
				if (cnt==0) {
					cout << "error"<<"\n";
					cur = false;
					break;
				}
				else {
					if (temp) {
						start++;
						cnt--;
					}
					else
						cnt--;
				}
			}
		}

		if(cur)
			cout << "[";
		while (cur) {
			if (temp) {
				if (cnt==0) {
					cout << "]\n";
					break;
				}
				cout << arr[start++];
				cnt--;
				if (cnt==0) {
					cout << "]\n";
					break;
				}
				cout << ",";
			}
			else {
				if (cnt==0) {
					cout << "]\n";
					break;
				}
				cout << arr[start + --cnt];
				if (cnt==0) {
					cout << "]\n";
					break;
				}
				cout << ",";
			}
		}
		start = 0;
	}
}
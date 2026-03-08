#include<iostream>
#include<stack>
using namespace std;

int arr[152]{ 0 };
int main() {
	int n,cnt=0;
	bool id;
	string str;
	stack<bool>a;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'S') { //싱글
			a.push(0); //컵홀더
			a.push(1); //좌석
		}
		else if (str[i] == 'L') { //커플
			a.push(0); //컵홀더
			a.push(1); //좌석
			a.push(1); //좌석
			i++;
		}
	}
	a.push(0); //컵홀더

	while(a.size()>1) {
		id = a.top();
		a.pop();
		if (!id) {//컵홀더라면
			if (a.top()) {//다음이 좌석이라면
				a.pop();
				cnt++;
			}
		}
		if (id) {//좌석이라면
			if (!a.top()) {//다음이 컵홀더라면
				a.pop();
				cnt++;
			}
		}
	}
	cout << cnt;
}
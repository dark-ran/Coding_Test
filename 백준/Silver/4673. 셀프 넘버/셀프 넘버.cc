#include<iostream>

using namespace std;

bool board[10002];

int main(){
	int cur, temp;
	for(int i=1;i<10000;i++){
		cur = temp = i;
		while (temp > 0) {
			cur += temp % 10;
			temp /= 10;
		}
		board[cur] = true;
	}
	for (int i = 1; i < 10000; i++) {
		if (!board[i])
			cout << i<<"\n";
	}
}
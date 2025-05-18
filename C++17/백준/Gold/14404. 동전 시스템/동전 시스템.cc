#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

const int MAX = 201 * 201;
bool visAB[MAX];
bool visX[MAX];
bool visY[MAX];
int A, B, X;

void calc() {
	int cnt = 0;
	for (int i = 1; i <= 200; i++) {
		bool flag = true;
		copy(visX, visX + MAX, visY);
		for (int j =i;j<MAX;j++){
			if (visY[j - i]) visY[j] = true;
		}
		for (int j = 0; j < MAX; j++) {
			if (visAB[j] && !visY[j]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> A >> B >> X;
	if (A % X == 0 && B % X == 0) {
		cout << -1;
		return 0;
	}


	for(int i=0;i<MAX;i+=A){
		for (int j = i; j < MAX; j += B) {
			visAB[j] = true;
		}
	}
	for (int i = 0; i < MAX; i += X) {
		visX[i] = true;
	}

	calc();

}
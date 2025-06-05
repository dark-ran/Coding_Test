#include<iostream>

using namespace std;

int arr[50];
int incl[50];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N == 1) {
		cout << "A";
		return 0;
	}
	else if (N == 2) {
		if (arr[0] != arr[1]) {
			cout << "A";
			return 0;
		}
		else {
			cout << arr[0];
			return 0;
		}
	}
	else if (arr[1] == arr[2]) {
		for (int i = 3; i <= N - 1; i++) {
			if (arr[i] != arr[1]) {
				cout << "B";
				return 0;
			}
		}
		cout << arr[1];
		return 0;
	}
	
	for (int i = 0; i < N - 1; i++) {
		incl[i] = arr[i + 1] - arr[i];
	}
	if (abs(incl[0]) > abs(incl[1])) {
		cout << "B";
		return 0;
	}

	int a;
	if (incl[0] == 0) {
		a = 0;
		if (incl[1] != 0) {
			cout << "B";
			return 0;
		}
	}
	else {
		a = incl[1] / incl[0];
		if (incl[0] * a != incl[1]) {
			cout << "B";
			return 0;
		}
	}

	for (int i = 1; i < N - 2; i++) {
		if (incl[i] * a != incl[i + 1]) {
			cout << "B";
			return 0;
		}
	}

	int b = arr[1] - arr[0] * a;
	cout << (arr[N - 1] * a + b);
}
#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, a;
	cin >> t;
	while (t--) {
		int arr[3]{ 0 };
		for (int i = 0; i < 10; i++) {
			cin >> a;
			if (arr[0] < a) {
				arr[0] = a;
				if (arr[1] < a) {
					arr[0] = arr[1];
					arr[1] = a;
					if (arr[2] < a) {
						arr[1] = arr[2];
						arr[2] = a;
					}
				}
			}
		}
		cout << arr[0]<<"\n";
	}
}
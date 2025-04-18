#include<iostream>
using namespace std;

char a[1000003];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool check = true;
	int cnt = 0;
	cin.getline(a, 1000002);
	for (int i = 0; a[i] != '\0';i++) {
		if (a[i] == ' ')
			check = true;
		else if (check) {
			cnt++;
			check = false;
		}
	}
	cout << cnt;
}
#include<iostream>

using namespace std;

bool v[21];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int M;
	cin >> M;
	string s;
	int a;
	while (M--) {
		cin >> s;
		if (s == "add") {
			cin >> a;
			v[a] = true;
			continue;
		}
		else if (s == "check") {
			cin >> a;
			cout << v[a] << "\n";
			continue;
		}
		else if (s == "remove") {
			cin >> a;
			v[a] = false;
			continue;
		}
		else if (s == "toggle") {
			cin >> a;
			v[a] = !v[a];
			continue;
		}
		else if (s == "all") {
			for (int i = 1;i <= 20;i++)
				v[i] = true;
			continue;
		}
		else if (s == "empty") {
			for (int i = 1;i <= 20;i++)
				v[i] = false;
			continue;
		}
	}
}
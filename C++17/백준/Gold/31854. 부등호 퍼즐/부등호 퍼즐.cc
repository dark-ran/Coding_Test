#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>v(n * n);
	vector<int>res(n * n);
	vector<int>arr(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char c;
			cin >> c;
			if (c == '<') {
				v[n * i + j].push_back(n * i + j + 1);
				arr[n * i + j + 1]++;
			}
			else {
				v[n * i + j + 1].push_back(n * i + j);
				arr[n * i + j]++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '<') {
				v[n * i + j].push_back(n * (i + 1) + j);
				arr[n * (i + 1) + j]++;
			}
			else {
				v[n * (i + 1) + j].push_back(n * i + j);
				arr[n * i + j]++;
			}
		}
	}

	int cnt = 1;
	queue<int>q;
	for (int i = 0; i < n * n; i++) {
		if (arr[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		res[idx] = cnt++;
		for (int a : v[idx]) {
			arr[a]--;
			if (arr[a] == 0)
				q.push(a);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i * n + j] << " ";
		}
		cout << "\n";
	}
}
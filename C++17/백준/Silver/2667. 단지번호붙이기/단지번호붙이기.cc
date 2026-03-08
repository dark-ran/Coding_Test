#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string arr[26];
vector<int>v;
int n;

void dfs(int x, int y, int &temp) {
	if (x < 0 || x>n-1 || y < 0 || y>n-1 || arr[x][y]=='0') return;
	arr[x][y] = '0';
	temp++;
	int dx[4] = {1,0,-1,0};
	int dy[4] = { 0,-1,0,1 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny, temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int temp, tot = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]=='1') {
				temp = 0;
				tot++;
				dfs(i, j, temp);
				v.push_back(temp);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << tot << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}
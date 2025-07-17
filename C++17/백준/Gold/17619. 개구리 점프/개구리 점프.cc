#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

struct s {
	int x1, x2, idx;
};
bool cmp(s& a, s& b) {
	if (a.x1 != b.x1)
		return a.x1 < b.x1;
	return a.x2 < b.x2;
}

vector<s>arr;
int par[100'001];

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void Union(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x < y)
		par[y] = par[x];
	else
		par[x] = par[y];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, Q, x;
	cin >> N >> Q;
	arr.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> arr[i].x1 >> arr[i].x2 >> x;
		arr[i].idx = i + 1;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 1;i <= N;i++)
		par[i] = i;

	for (int i = 0;i < N;i++) {
		int MAX = arr[i].x2;
		int p = arr[i].idx;
		while (i + 1 < N && arr[i + 1].x1 <= MAX) { //다음 다리가 연결될 때
			MAX = MAX > arr[i + 1].x2 ? MAX : arr[i + 1].x2;
			i++;
			Union(p, arr[i].idx);
		}
	}


	for (int i = 0;i < Q;i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
}
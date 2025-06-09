#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
const int ISIZE = 1 << 22;
char ibuf[ISIZE];
char* in_ptr = ibuf;
char* end_ptr = ibuf;
char get() {
	if (in_ptr == end_ptr) {
		end_ptr = ibuf + fread(ibuf, 1, ISIZE, stdin);
		in_ptr = ibuf;
	}
	return *in_ptr++;
}
void read(int& x) {
	x = 0;
	char c;
	while ((c = get()) < '0');
	for (;c >= '0';c = get()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
}


vector<int>arr[100'001];
int N, ans[100'001];
bool vis[100'001];
queue<int>q;

bool bfs() {
	static int idx = 0;
	if (ans[0] != 0) {
		return false;
	}

	q.push(0);
	vis[0] = true;
	int cur, nxt = ans[++idx];
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		while (true) {
			if (vis[nxt]) return false;
			if (!binary_search(arr[cur].begin(), arr[cur].end(), nxt)) break;
			q.push(nxt);
			vis[nxt] = true;
			nxt = ans[++idx];
			if (idx >= N) return true;
		}
	}
	return idx == N;
}

int main() {
	int a, b;
	read(N);
	for (int i = 1;i < N;i++) {
		read(a);
		read(b);
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0;i < N;i++) {
		read(ans[i]);
		ans[i]--;
		sort(arr[i].begin(), arr[i].end());
	}
	cout << bfs();
}
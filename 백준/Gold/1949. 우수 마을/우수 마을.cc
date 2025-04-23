#include<stdio.h>
#include<vector>

using namespace std;

char output_buffer[10];
char* out_ptr = output_buffer;

void write(int x) {
	if (x > 9)write(x / 10);
	*out_ptr++ = x % 10 + '0';
}
void write(char x) {
	*out_ptr++ = x;
}
void flush() {
	fwrite(output_buffer, 1, out_ptr - output_buffer, stdout);
}

char get() {
	static char buf[3000], * S = buf, * T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 1, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
void read(int& x) {
	static char c; x = 0;
	for (c = get(); c < '0'; c = get());
	for (; c >= '0'; c = get()) x = x * 10 + c - '0';
}

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& arr, vector<vector<int>>& dp) {
	dp[node][1] = arr[node];
	for (int child : adj[node]) {
		if (child == parent) continue;
		dfs(child, node, adj, arr, dp);
		dp[node][0] += max(dp[child][0], dp[child][1]);
		dp[node][1] += dp[child][0];
	}
}

int main() {
	int n;
	read(n);
	vector<int>arr(n);
	vector<vector<int>>path(n);
	for (int i = 0; i < n; i++)read(arr[i]);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		read(x), read(y);
		path[x - 1].push_back(y - 1);
		path[y - 1].push_back(x - 1);
	}
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dfs(0, -1, path, arr, dp);
	write(dp[0][0] > dp[0][1] ? dp[0][0] : dp[0][1]);
	flush();
}
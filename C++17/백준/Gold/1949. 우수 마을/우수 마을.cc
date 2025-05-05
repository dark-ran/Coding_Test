#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int BUF_SIZE = 30000;
char output_buffer[BUF_SIZE];
char* out_ptr = output_buffer;

inline void write(int x) {
    if (x == 0) {
        *out_ptr++ = '0';
        return;
    }

    char buf[12], * p = buf + 11;
    *p = '\0';
    while (x) {
        *--p = '0' + (x % 10);
        x /= 10;
    }
    while (*p) *out_ptr++ = *p++;
}

inline void write(char x) {
    *out_ptr++ = x;
}

inline void flush() {
    fwrite(output_buffer, 1, out_ptr - output_buffer, stdout);
    out_ptr = output_buffer;
}

char input_buffer[BUF_SIZE];
char* in_ptr = input_buffer;
char* end_ptr = input_buffer;

inline char get() {
    if (in_ptr == end_ptr) {
        end_ptr = input_buffer + fread(input_buffer, 1, BUF_SIZE, stdin);
        in_ptr = input_buffer;
        if (in_ptr == end_ptr) return EOF;
    }
    return *in_ptr++;
}

inline void read(int& x) {
    x = 0;
    char c;
    while ((c = get()) < '0' && c != EOF);
    if (c == EOF) return;
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
    vector<int> arr(n);
    vector<vector<int>> path(n);

    for (int i = 0; i < n; i++) read(arr[i]);

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
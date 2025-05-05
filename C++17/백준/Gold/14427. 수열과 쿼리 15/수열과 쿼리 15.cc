#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 0x7FFFFFFF;
char output_buffer[500000];
char* out_ptr = output_buffer;

void write(int x) {
	if (x > 9) write(x / 10);
	*out_ptr++ = x % 10 + '0';
}

void flush_output() {
	fwrite(output_buffer, 1, out_ptr - output_buffer, stdout);
}

char get() {
	static char buf[500000], * S = buf, * T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 500000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
void read(int& x) {
	static char c; x = 0;
	for (c = get(); c < '0'; c = get());
	for (; c >= '0'; c = get()) x = x * 10 + c - '0';
}

void init(vector<pair<int, int>>& tree, int size) {
	for (int i = size - 1; i > 0; i--)
		tree[i] = tree[i * 2] < tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
}

void modify(vector<pair<int, int>>& tree, int size, int idx, int val) {
	tree[size + idx - 1] = { val,idx };
	int i = (size + idx - 1) >> 1;
	for (; i > 0; i >>= 1) {
		pair<int, int>s = tree[i * 2].first <= tree[i * 2 + 1].first ? tree[i * 2] : tree[i * 2 + 1];
		if (tree[i] == s) return;
		tree[i] = s;
	}
}

int main() {
	int N;
	read(N);
	int size = 1 << (int)ceil(log2(N));
	vector<pair<int, int>>tree(size << 1, { MAX,0 });
	for (int i = 0; i < N; i++) {
		read(tree[size + i].first);
		tree[size + i].second = i + 1;
	}
	init(tree, size);
	read(N);
	while (N--) {
		int x;
		read(x);
		if (x == 2) {
			write(tree[1].second);
			*out_ptr++ = '\n';
		}
		else {
			int y, z;
			read(y);
			read(z);
			modify(tree, size, y, z);
		}
	}
	flush_output();
}
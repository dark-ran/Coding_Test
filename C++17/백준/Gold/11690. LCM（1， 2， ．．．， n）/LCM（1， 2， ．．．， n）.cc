#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

const int ISIZE = 16;
char ibuffer[ISIZE];
char* start_ptr = ibuffer;
char* end_ptr = ibuffer;
inline char get() {
	if (start_ptr == end_ptr) {
		end_ptr = ibuffer + fread(ibuffer, 1, ISIZE, stdin);
		start_ptr = ibuffer;
	}
	return *start_ptr++;
}
inline long long nextlong() {
	long long x = 0;
	char c;
	for (c = get(); c >= '0'; c = get()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
	return x;
}

const int OSIZE = 16;
char obuffer[OSIZE];
char* oidx = obuffer;
inline void write(long long x) {
	char temp[20];
	int idx = 0;
	do {
		temp[idx++] = (x % 10) + '0';
		x /= 10;
	} while (x > 0);
	for (int i = idx - 1; i >= 0; --i) {
		*oidx++ = temp[i];
	}
}
inline void flush() {
	fwrite(obuffer, 1, oidx - obuffer, stdout);
}

int main() {
	const long long MOD = 4294967296;
	long long n = nextlong();
	vector<bool>vis(n + 1);
	for (int i = 4; i <= n; i += 2)
		vis[i] = true;
	int sqrt_n = sqrt(n);
	for (int i = 3; i <= sqrt_n; i += 2) {
		if (!vis[i]) {
			for (int j = i * i; j <= n; j += 2 * i) {
				vis[j] = true;
			}
		}
	}
	long long cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			long j = i;
			while (j * i <= n) {
				j *= i;
			}
			cnt = (cnt * j) % MOD;
			if (cnt < 0)cnt += MOD;
		}
	}
	if (cnt < 0)cnt += MOD;
	write(cnt);
	flush();
}
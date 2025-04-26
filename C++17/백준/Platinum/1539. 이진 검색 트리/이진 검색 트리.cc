#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

const int BUF_SIZE = 2000000;
char output_buffer[BUF_SIZE];
char* out_ptr = output_buffer;

inline void write(long long x) {
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

int len[1000001] = {0};

int main() {
    int n,num;
    read(n);
    long long ans = 0;
    set<int> tree;
    
    for (int i = 0; i < n; i++) {
        read(num);
        auto higher = tree.upper_bound(num);
        auto lower = tree.lower_bound(num);
        
        if (lower != tree.begin()) {
            lower--;
        } else {
            lower = tree.end();
        }
        
        if (higher == tree.end()) {
            if (lower == tree.end()) {
                len[num] = 1;
            } else {
                len[num] = len[*lower] + 1;
            }
        } else {
            if (lower == tree.end()) {
                len[num] = len[*higher] + 1;
            } else {
                len[num] = max(len[*higher], len[*lower]) + 1;
            }
        }
        ans += len[num];
        tree.insert(num);
    }
    write(ans);
    flush();
}
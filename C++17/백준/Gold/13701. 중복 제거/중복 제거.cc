#include <iostream>
#include <bitset>
using namespace std;

bitset<33554433> vis;

const int BUFFER_SIZE = 1048576;
char input_buffer[BUFFER_SIZE];
char output_buffer[BUFFER_SIZE];
int input_pos = 0, input_len = 0;
int output_pos = 0;

inline int readInt() {
    int num = 0;
    bool is_num = false;

    while (true) {
        if (input_pos >= input_len) {
            input_len = fread(input_buffer, 1, BUFFER_SIZE, stdin);
            input_pos = 0;
            if (input_len == 0) return is_num ? num : -1; // EOF
        }

        char c = input_buffer[input_pos++];
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            is_num = true;
        }
        else if (is_num) {
            return num;
        }
    }
}

inline void writeInt(int num) {
    if (num == 0) {
        output_buffer[output_pos++] = '0';
    }
    else {
        int s = output_pos;
        while (num > 0) {
            output_buffer[output_pos++] = '0' + (num % 10);
            num /= 10;
        }
        int e = output_pos - 1;
        while (s < e) {
            char t = output_buffer[s];
            output_buffer[s] = output_buffer[e];
            output_buffer[e] = t;
            s++, e--;
        }
    }
    output_buffer[output_pos++] = ' ';

    if (output_pos > BUFFER_SIZE - 20) {
        fwrite(output_buffer, 1, output_pos, stdout);
        output_pos = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    setvbuf(stdin, nullptr, _IOFBF, BUFFER_SIZE);
    setvbuf(stdout, nullptr, _IOFBF, BUFFER_SIZE);

    int a;
    while (true) {
        a = readInt();
        if (a == -1) break;

        if (!vis[a]) {
            vis[a] = true;
            cout << a << " ";
        }
    }
    fwrite(output_buffer, 1, output_pos, stdout);
}
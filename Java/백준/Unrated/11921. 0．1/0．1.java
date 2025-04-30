public class Main {
    static byte[] ibuf = new byte[1 << 20];
    static int idx, size;

    static byte read() throws Exception {
        if (idx == size) {
            size = System.in.read(ibuf, idx = 0, ibuf.length);
        }
        return ibuf[idx++];
    }

    static int nextInt() throws Exception {
        int n = 0;
        byte c;
        while ((c = read()) < '0');
        do {
            n = (n << 3) + (n << 1) + (c & 15);
        } while ((c = read()) >= '0');
        return n;
    }
    static byte[] outputBuffer = new byte[1<<5];
    static int ptr = 0;

    static void write(int x) {
        if (x == 0) {
            outputBuffer[ptr++] = '0';
            return;
        }
        int start = ptr;
        while (x > 0) {
            outputBuffer[ptr++] = (byte) (x % 10 + '0');
            x /= 10;
        }
        int end = ptr - 1;
        while (start < end) {
            byte temp = outputBuffer[start];
            outputBuffer[start] = outputBuffer[end];
            outputBuffer[end] = temp;
            start++;
            end--;
        }
    }
    static void write(long x) {
        if (x == 0) {
            outputBuffer[ptr++] = '0';
            return;
        }
        int start = ptr;
        while (x > 0) {
            outputBuffer[ptr++] = (byte) (x % 10 + '0');
            x /= 10;
        }
        int end = ptr - 1;
        while (start < end) {
            byte temp = outputBuffer[start];
            outputBuffer[start] = outputBuffer[end];
            outputBuffer[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) throws Exception {
        nextInt();
        long sum = 0;
        for (int i = 0; i < 200000; i++) {
            sum += nextInt();
        }
        write(200000);
        outputBuffer[ptr++]='\n';
        write(sum);
        System.out.write(outputBuffer,0,ptr);
    }
}
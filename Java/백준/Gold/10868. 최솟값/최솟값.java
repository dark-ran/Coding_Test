import java.util.*;

public class Main {
    static final int ISIZE = 1 << 21;
    static byte[] ibuf = new byte[ISIZE];
    static int iidx, isize;

    static final int OSIZE = 1 << 21;
    static byte[] obuf = new byte[OSIZE];
    static int oidx = 0;

    static final int INF = Integer.MAX_VALUE;

    static byte read() throws Exception {
        if (iidx == isize) {
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
            if (isize == -1) ibuf[0] = -1;
        }
        return ibuf[iidx++];
    }

    static int nextInt() throws Exception {
        int n = 0;
        byte b;
        while ((b = read()) <= ' ') {
            if (b == -1) return -1;
        }
        do {
            n = n * 10 + (b & 15);
        } while ((b = read()) >= '0');
        return n;
    }

    static void write(int x){
        if (x == 0) {
            obuf[oidx++] = '0';
        } else {
            int s = oidx;
            while (x > 0) {
                obuf[oidx++] = (byte) (x % 10 + '0');
                x /= 10;
            }
            int e = oidx - 1;
            while (s < e) {
                byte t = obuf[s];
                obuf[s] = obuf[e];
                obuf[e] = t;
                s++;
                e--;
            }
        }
        obuf[oidx++] = '\n';
    }

    static void flush(){
        System.out.write(obuf, 0, oidx);
    }

    public static void main(String[] args) throws Exception {
        int n = nextInt();
        int m = nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
        }

        int[] tree1 = new int[n + 1];
        int[] tree2 = new int[n + 1];
        Arrays.fill(tree1, INF);
        Arrays.fill(tree2, INF);


        for (int i = 1; i <= n; i++) {
            int val = arr[i - 1];
            for (int j = i; j <= n; j += j & -j) {
                if (val < tree1[j]) tree1[j] = val;
            }
            for (int j = i; j > 0; j -= j & -j) {
                if (val < tree2[j]) tree2[j] = val;
            }
        }

        while (m-- > 0) {
            int l = nextInt();
            int r = nextInt();
            int min = INF;


            int idx = l;
            while (idx + (idx & -idx) <= r) {
                if (tree2[idx] < min) min = tree2[idx];
                idx += idx & -idx;
            }
            if (arr[idx - 1] < min) min = arr[idx - 1];

            idx = r;
            while (idx - (idx & -idx) >= l) {
                if (tree1[idx] < min) min = tree1[idx];
                idx -= idx & -idx;
            }
            if (arr[idx - 1] < min) min = arr[idx - 1];

            write(min);
        }
        flush();
    }
}
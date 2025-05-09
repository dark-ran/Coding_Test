import java.util.*;

public class Main {
    static int ISIZE = 1<<23;
    static int iidx, isize;
    static final byte[] ibuf = new byte[ISIZE];
    static byte read() throws Exception {
        if (iidx == isize)
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        return ibuf[iidx++];
    }
    static int nextInt() throws Exception {
        int n = 0;
        byte c;
        while ((c = read()) >= '0') {
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }

    static final int OSIZE = 1<<17;
    static int oidx = 0;
    static final byte[] obuf = new byte[OSIZE];
    static void write(long x) {
        if (x == 0) {
            obuf[oidx++] = '0';
            obuf[oidx++] = '\n';
            return;
        }
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
        obuf[oidx++] = '\n';
    }

    public static void main(String[] args) throws Exception {
        int n;
        while ((n = nextInt()) != 0) {
            int[] heights = new int[n];
            for (int i = 0; i < n; i++) {
                heights[i] = nextInt();
            }

            long maxArea = 0;
            Deque<Integer> stack = new ArrayDeque<>();

            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && heights[stack.peek()] > heights[i]) {
                    int height = heights[stack.pop()];
                    int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                    maxArea = Math.max(maxArea, (long) height * width);
                }
                stack.push(i);
            }

            while (!stack.isEmpty()) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? n : n - stack.peek() - 1;
                maxArea = Math.max(maxArea, (long) height * width);
            }

            write(maxArea);
        }
        System.out.write(obuf, 0, oidx);
    }
}
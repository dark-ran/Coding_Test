import java.util.*;
import java.util.BitSet;

public class Main {
    public static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) < 48);
        do {
            n = (n << 3) + (n << 1) + (c & 15);
        } while ((c = System.in.read()) >= 48);
        return n;
    }

    public static void main(String[] args) throws Exception {
        int f = read(), s = read(), g = read(), u = read(), d = read();

        if (s == g) {
            System.out.print(0);
            return;
        }

        if ((u == 0 && g > s) || (d == 0 && g < s)) {
            System.out.print("use the stairs");
            return;
        }

        BitSet vis = new BitSet(f + 1);
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(s, 0));
        vis.set(s);

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            int idx = cur.first;
            int num = cur.second;
            if (u > 0) {
                int next = idx + u;
                if (next <= f && !vis.get(next)) {
                    if (next == g) {
                        System.out.print(num + 1);
                        return;
                    }
                    vis.set(next);
                    q.offer(new Pair(next, num + 1));
                }
            }
            if (d > 0) {
                int next = idx - d;
                if (next >= 1 && !vis.get(next)) {
                    if (next == g) {
                        System.out.print(num + 1);
                        return;
                    }
                    vis.set(next);
                    q.offer(new Pair(next, num + 1));
                }
            }
        }

        System.out.print("use the stairs");
    }

    static class Pair {
        int first, second;
        Pair(int x, int y) {
            this.first = x;
            this.second = y;
        }
    }
}
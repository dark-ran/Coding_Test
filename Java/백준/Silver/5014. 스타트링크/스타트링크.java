import java.util.*;

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

        if (u == 0 && d == 0) {
            System.out.print("use the stairs");
            return;
        }

        boolean[] vis = new boolean[f + 1]; // 1-based
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(s, 0));
        vis[s] = true;

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            int idx = cur.first;
            int num = cur.second;

            if (u != 0) {
                int next = idx + u;
                if (next <= f && !vis[next]) {
                    if (next == g) {
                        System.out.print(num + 1);
                        return;
                    }
                    vis[next] = true;
                    q.offer(new Pair(next, num + 1));
                }
            }
            if (d != 0) {
                int next = idx - d;
                if (next >= 1 && !vis[next]) {
                    if (next == g) {
                        System.out.print(num + 1);
                        return;
                    }
                    vis[next] = true;
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
public class Main {
    static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) < '0');
        do {
            n = (n << 3) + (n << 1) + (c & 15);
        } while ((c = System.in.read()) >= '0');
        return n;
    }

    static byte[] outputBuffer = new byte[30000000];
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


    public static void main(String[] args) throws Exception {
        int INF = 0x3f3f3f3f;
        int n = read(), m = read();
        int[][] cost = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cost[i][j] = INF;
            cost[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = read(), b = read(), c = read();
            cost[a][b] = cost[a][b]<c?cost[a][b]:c;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cost[i][j] = cost[i][j]<cost[i][k]+cost[k][j]?cost[i][j]:cost[i][k]+cost[k][j];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] == INF) {
                    outputBuffer[ptr++] = '0';
                } else {
                    write(cost[i][j]);
                }
                outputBuffer[ptr++] = ' ';
            }
            outputBuffer[ptr++] = '\n';
        }
        System.out.write(outputBuffer, 0, ptr);
    }
}
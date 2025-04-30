import java.io.*;

public class Main {
    static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) >= '0') {
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }

    public static void main(String[] args) throws Exception {
        int n = read();
        int k = (int) Math.ceil((Math.sqrt(8L * n + 1) - 1) / 2);
        
        int prevSum = k * (k - 1) / 2;
        int pos = n - prevSum;

        if (k % 2 == 1) {
            System.out.println((k - pos + 1) + "/" + pos);
        } else {
            System.out.println(pos + "/" + (k - pos + 1));
        }
    }
}
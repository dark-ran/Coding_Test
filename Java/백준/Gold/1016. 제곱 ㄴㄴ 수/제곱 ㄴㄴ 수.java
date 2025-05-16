import java.util.*;

public class Main {
    static final int ISIZE = 1 << 10;
    static byte[] ibuf = new byte[ISIZE];
    static int iidx, isize;

    static byte read() throws Exception {
        if (iidx == isize) {
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        }
        return ibuf[iidx++];
    }

    static long nextInt() throws Exception {
        long n = 0;
        byte b;
        while ((b = read()) >= '0'){
            n = (n << 3) + (n << 1) + (b & 15);
        }
        return n;
    }

    static final int OSIZE = 1<<4;
    static byte[] obuf = new byte[OSIZE];
    static int oidx;

    static void write(int n) {
        if(n==0){
            obuf[oidx++]='0';
            return;
        }
        int s = oidx;
        while (n > 0) {
            obuf[oidx++] = (byte)((n % 10) + '0');
            n /= 10;
        }
        int e = oidx - 1;
        while (s < e) {
            byte t = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = t;
            s++; e--;
        }
    }


    public static void main(String[] args) throws Exception {
        long min = nextInt(), max = nextInt();
        int diff = Math.toIntExact(max-min) + 1;
        boolean[]vis = new boolean[diff];

        for (long i = 2; i * i <= max; i++) {
            long square = i * i;
            long start = min % square == 0 ? min : min + (square - (min % square));

            for (long j = start; j <= max; j += square) {
                vis[(int)(j - min)] = true;
            }
        }

        int cnt = 0;
        for (boolean b : vis) {
            if (!b) cnt++;
        }

        write(cnt);
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
}
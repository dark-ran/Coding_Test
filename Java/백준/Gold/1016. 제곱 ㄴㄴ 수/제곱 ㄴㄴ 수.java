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
        int diff = (int)(max-min+1);
        BitSet vis = new BitSet(diff);

        long maxsqare = (long)Math.sqrt(max);
        for (long i = 2; i <= maxsqare; i++) {
            long square = i * i;
            long start = ((min + square - 1)/square) * square;

            for (long j = start; j <= max; j += square) {
                vis.set((int)(j-min));
            }
        }

        int cnt = diff - vis.cardinality();

        write(cnt);
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
}
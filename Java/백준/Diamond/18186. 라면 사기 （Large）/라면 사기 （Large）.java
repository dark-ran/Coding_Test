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
        while ((c = read()) >= '0'){
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }

    static final int OSIZE = 1<<8;
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
    }

    public static void main(String[] args) throws Exception {
        int n=nextInt(),b=nextInt(),c=nextInt();
        long cost=0;
        if(b<=c){
            for(int i=0;i<n;i++){
                cost+=nextInt();
            }
            write(cost * b);
            System.out.write(obuf,0,oidx);
            return;
        }
        int[]arr = new int[n + 2];
        int q = b+c,w=b+2*c;
        for(int i=0;i<n;i++){
            arr[i]=nextInt();
        }
        for(int i=0;i<n;i++){
            if(arr[i+1]>arr[i+2]) {
                int cnt = Math.min(arr[i], arr[i + 1] - arr[i+2]);
                cost += (long)q * cnt;
                arr[i] -= cnt;
                arr[i + 1] -= cnt;

                cnt = Math.min(arr[i], Math.min(arr[i+1],arr[i+2]));
                cost +=  (long)w * cnt;
                arr[i] -= cnt;
                arr[i + 1] -= cnt;
                arr[i + 2] -= cnt;


                cost += (long)b * arr[i];
            }
            else{
                int cnt = Math.min(arr[i], Math.min(arr[i + 1], arr[i + 2]));
                cost += (long)w * cnt;
                arr[i] -= cnt;
                arr[i + 1] -= cnt;
                arr[i + 2] -= cnt;

                cnt = Math.min(arr[i], arr[i + 1]);
                cost += (long)q * cnt;
                arr[i] -= cnt;
                arr[i + 1] -= cnt;

                cost += (long)b * arr[i];
            }
        }
        write(cost);
        System.out.write(obuf,0,oidx);
    }
}
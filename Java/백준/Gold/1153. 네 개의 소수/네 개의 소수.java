import java.util.*;

public class Main {
    static final int ISIZE = 1 << 22;
    static byte[] ibuf = new byte[ISIZE];
    static int iidx, isize;

    static byte read() throws Exception {
        if (iidx == isize) {
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        }
        return ibuf[iidx++];
    }

    static int nextInt() throws Exception {
        int n = 0;
        byte b;
        while ((b = read()) >= '0'){
            n = (n << 3) + (n << 1) + (b & 15);
        }
        return n;
    }

    static final int OSIZE = 1<<6;
    static byte[] obuf = new byte[OSIZE];
    static int oidx;

    static void write(long n) {
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
        obuf[oidx++]=' ';
    }


    public static void main(String[] args) throws Exception {
        int n = nextInt();
        if(n<8){
            obuf[oidx++]='-';
            obuf[oidx++]='1';
            System.out.write(obuf,0,oidx);
            System.out.flush();
            return;
        }
        boolean[]vis = new boolean[n+1];
        for(int i=2;i*i<=n;i++)
            for(int j=2 * i;j<=n;j+=i)
                vis[j]=true;

        if(n%2==0){
            write(2);
            write(2);
            for(int i=2;i<n-4;i++){
                if(!vis[i]&&!vis[n-4-i]){
                    write(i);
                    write(n-4-i);
                    break;
                }
            }
        }
        else{
            write(2);
            write(3);
            for(int i=2;i<=n-5;i++){
                if(!vis[i]&&!vis[n-i-5]) {
                    write(i);
                    write(n - i - 5);
                    break;
                }
            }
        }
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
}
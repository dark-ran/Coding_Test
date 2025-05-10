import java.util.*;
public class Main {
    static int ISIZE = 1<<21;
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
        boolean flag=false;
        if((c=read())==45){
            flag=true;
            c=read();
        }
        do{
            n = (n << 3) + (n << 1) + (c & 15);
        }while ((c = read()) >= '0');
        return flag?-n:n;
    }

    static final int OSIZE = 1<<20;
    static int oidx = 0;
    static final byte[] obuf = new byte[OSIZE];
    static void write(int x) {
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
        int n = nextInt();
        int h = (int)Math.ceil(Math.log(1000000)/Math.log(2));
        int size = (1<<h);
        int[]tree = new int[size<<1];
        while(n-->0){
            int a = nextInt();
            if(a==1){
                int b=nextInt();
                int idx = 1;
                tree[idx]--;
                while(true){
                    if(idx>=size) break;
                    if(tree[idx<<1]>=b){
                        idx<<=1;
                        tree[idx]--;
                    }
                    else {
                        b-=tree[idx<<1];
                        idx = (idx << 1) + 1;
                        tree[idx]--;
                    }
                }
                write(idx-size + 1);
            }
            else{
                int b=nextInt(),c=nextInt();
                int idx = size+b-1;
                while(idx>0){
                    tree[idx]+=c;
                    idx>>=1;
                }
            }
        }
        System.out.write(obuf,0,oidx);
    }
}
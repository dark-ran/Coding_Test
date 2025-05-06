public class Main{
    static int isize,iidx;
    static byte[]ibuf = new byte[13];
    static byte read()throws Exception{
        if(isize==iidx)
            isize = System.in.read(ibuf,iidx = 0,13);
        return ibuf[iidx++];
    }
    static long nextInt()throws Exception{
        long n=0;
        byte c;
        while((c=read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    static int oidx = 0;
    static byte[]obuf = new byte[13];
    static void func(long n){
        long res = n;
        if (n % 2 == 0) {
            res -= res / 2;
            while (n % 2 == 0) n /= 2;
        }
        for (long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                res -= res / i;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) res -= res / n;
        while(res>0){
            obuf[oidx++]=(byte)(res%10+'0');
            res/=10;
        }
        int s=0,e=oidx-1;
        while(s<e){
            byte temp = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = temp;
            s++;
            e--;
        }
    }

    public static void main(String[] args)throws Exception{
        long n = nextInt();
        func(n);
        System.out.write(obuf,0,oidx);
    }
}
public class Main{
    static final int ISIZE = 1<<22;
    static int iidx,isize;
    static byte[]ibuf = new byte[ISIZE];
    static byte read()throws Exception{
        if(iidx==isize)
            isize = System.in.read(ibuf,iidx=0,ISIZE);
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
    static int oidx=0;
    static byte[]obuf = new byte[1<<20];
    static void write(long x){
        if(x==0){
            obuf[oidx++]='0';
            obuf[oidx++]='\n';
            obuf[oidx++]='3';
            return;
        }
        int s = oidx;
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int e = oidx-1;
        while(s<e){
            byte t = obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=t;
            s++;
            e--;
        }
        obuf[oidx++]='\n';
        obuf[oidx++]='3';
    }
    public static void main(String[]args)throws Exception{
        long n = nextInt();
        write(n*(n-1)*(n-2)/6);
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
    
}
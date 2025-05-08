public class Main {
    static final int ISIZE = 1<<5;
    static int isize,iidx;
    static byte[]ibuf = new byte[ISIZE];
    static byte read()throws Exception{
        if(isize==iidx){
            isize=System.in.read(ibuf,iidx=0,ISIZE);
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte b;
        while((b=read())>='0'){
            n=(n<<3)+(n<<1)+(b&15);
        }
        return n;
    }
    static byte[]obuf = new byte[1<<5];
    static int oidx = 0;
    static void write(int x){
        if(x==0){
            obuf[oidx++]='0';
            return;
        }
        int s=oidx;
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int e=oidx-1;
        while(s<e){
            byte t = obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=t;
            s++;
            e--;
        }
    }
    public static void main(String[] args)throws Exception{
        int x = nextInt();
        int y = nextInt();
        int w = nextInt();
        int h = nextInt();
        int x_min = Math.min(x, w-x);
        int y_min = Math.min(y, h-y);

        write(Math.min(x_min, y_min));
        System.out.write(obuf,0,oidx);
    }

}
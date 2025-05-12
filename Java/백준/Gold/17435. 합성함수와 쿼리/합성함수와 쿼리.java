public class Main{
    static final int ISIZE = 1<<23;
    static int iidx,isize;
    static byte[]ibuf = new byte[ISIZE];
    static byte read()throws Exception{
        if(iidx==isize)
            isize=System.in.read(ibuf,0,ISIZE);
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

    static final int OSIZE = 1<<21;
    static int oidx = 0;
    static byte[]obuf = new byte[OSIZE];
    static void write(int x){
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
    }


    public static void main(String[] args)throws Exception{
        int m=nextInt();
        int[][]arr = new int[20][m];
        for(int i=0;i<m;i++)arr[0][i]=nextInt()-1;

        int[]log = new int[500001];
        for(int i=2;i<=500000;i++){
            log[i]=log[i>>1]+1;
        }

        int[]pow = new int[20];
        pow[0]=1;
        for(int i=1;i<20;i++){
            pow[i]=pow[i-1]<<1;
        }

        for(int i=1;pow[i]<=500001;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = arr[i-1][arr[i-1][j]];
            }
        }

        int q = nextInt();
        while(q-->0){
            int n=nextInt()-1,x=nextInt()-1;
            while(n>0){
                int k = log[n];
                x=arr[k][x];
                n-=pow[k];
            }
            x=arr[0][x];
            write(x+1);
        }
        System.out.write(obuf,0,oidx);
    }
}
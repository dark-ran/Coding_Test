import java.util.Arrays;
public class Main{
    static int MOD = 1000000007;
    static int isize,iidx;
    static byte[]ibuf=new byte[1<<22];
    static byte read()throws Exception{
        if(isize==iidx){
            isize=System.in.read(ibuf,0,1<<22);
            iidx=0;
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=read())>='0');
        return n;
    }
    static void insert(int[]arr, int n)throws Exception{
        for(int i=0;i<n;i++){
            arr[i]=nextInt();
        }
    }
    static int oidx=0;
    static byte[]obuf = new byte[10];
    static void write(long x){
        if(x==0) {
            obuf[oidx++]='0';
            return;
        }
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int s=0,e=oidx-1;
        while(s<e){
            byte temp = obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=temp;
            s++;
            e--;
        }
    }

    static void pow(long[]num,int n){
        num[0]=1;
        for(int i=1;i<n;i++){
            num[i]=(num[i-1]*2)%MOD;
        }
    }

    public static void main(String[] args)throws Exception {
        int n=nextInt();
        int[]arr = new int[n];
        insert(arr,n);
        Arrays.sort(arr);
        long[]num = new long[n];
        pow(num,n);
        long sum=0;
        for(int i=0;i<n;i++){
            long MAX = arr[i] * num[i] ;
            long MIN = arr[i] * num[n-1-i] % MOD;
            sum = (sum + MAX - MIN);
            if(sum>MOD) sum %= MOD;
        }
        write(sum);
        System.out.write(obuf,0,oidx);
    }
}
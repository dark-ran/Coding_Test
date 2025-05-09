import java.util.Map;
import java.util.HashMap;
public class Main{
    static int iidx,isize;
    static byte[]ibuf = new byte[1<<23];
    static byte read()throws Exception{
        if(isize==iidx)
            System.in.read(ibuf,iidx=0,1<<23);
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
    static int oidx=0;
    static byte[]obuf = new byte[1<<4];
    static void write(long x){
        if(x==0){
            obuf[oidx++]='0';
            return;
        }
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int s=0,e=oidx-1;
        while(s<e){
            byte t = obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=t;
            s++;
            e--;
        }
    }

    public static void main(String[] args)throws Exception{
        int n=nextInt();
        int[]arr = new int[1000001];
        for(int i=0;i<n;i++) arr[nextInt()]=i;
        int[]res = new int[n];
        for(int i=0;i<n;i++) res[i]=arr[nextInt()];
        int[]tree = new int[n+1];
        long sum = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=res[i];j>0;j-=(j&-j)){
                sum+=tree[j];
            }
            for(int j=res[i]+1;j<=n;j+=(j&-j)){
                tree[j]++;
            }
        }
        write(sum);
        System.out.write(obuf,0,oidx);
    }
}
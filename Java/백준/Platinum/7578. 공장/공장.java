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
        Map<Integer,Integer>arr = new HashMap<>();
        int h = (int)Math.ceil(Math.log(n)/Math.log(2));
        int size = 1<<h;
        int[]tree = new int[size<<1];
        int[]res = new int[n];
        for(int i=0;i<n;i++) arr.put(nextInt(),i);
        for(int i=0;i<n;i++) res[i]=arr.get(nextInt());
        long sum = 0;
        for(int i=0;i<n;i++){
            int num = size + res[i];
            tree[num]++;
            for(num>>=1;num>0;num>>=1){
                tree[num]=tree[num<<1]+tree[num<<1|1];
            }
            int s=size + res[i] + 1,e=size+n-1;
            while(s<=e){
                if((s&1)!=0)
                    sum+=tree[s++];
                if((e&1)==0)
                    sum+=tree[e--];
                s>>=1;
                e>>=1;
            }
        }
        write(sum);
        System.out.write(obuf,0,oidx);
    }
}
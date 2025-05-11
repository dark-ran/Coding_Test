import java.util.*;
public class Main{
    static final int ISIZE = 1<<21;
    static int iidx,isize;
    static byte[]ibuf = new byte[ISIZE];
    static byte read()throws Exception{
        if(iidx==isize)
            isize=System.in.read(ibuf,iidx=0,ISIZE);
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
    static int oidx=0;
    static byte[]obuf = new byte[OSIZE];
    static void write(int x){
        int s = oidx;
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
        obuf[oidx++]='\n';
    }

    public static void main(String[]args)throws Exception{
        int n=nextInt(),m=nextInt();
        int h=(int)Math.ceil(Math.log(n)/Math.log(2));
        int size = 1<<h;
        int[]tree = new int[size<<1];
        for(int i=0;i<n;i++){
            tree[size+i]=nextInt();
        }
        for(int i=n;i<size;i++){
            tree[size+i]=1987654321;
        }
        for(int i=size-1;i>0;i--){
            tree[i]=Math.min(tree[i<<1],tree[i<<1|1]);
        }
        while(m-->0){
            int l=nextInt()+size-1;
            int r=nextInt()+size-1;
            int min = 1987654321;
            while(l<=r){
                if((l&1)==1)min=Math.min(min,tree[l++]);
                if((r&1)==0)min=Math.min(min,tree[r--]);
                l>>=1;
                r>>=1;
            }
            write(min);
        }
        System.out.write(obuf,0,oidx);
    }
}
public class Main{
    static final int ISIZE = 1<<23;
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
    static byte[]obuf = new byte[1<<23];
    static int oidx = 0;
    static void write(int x){
        if(x==0){
            obuf[oidx++]='0';
            obuf[oidx++]=' ';
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
        obuf[oidx++]=' ';
    }

    static void init(int[]tree,int n,int size){
        for(int i=0;i<n;i++){
            tree[size+i]=1;
        }
        for(int i=size-1;i>0;i--){
            tree[i]=tree[i<<1]+tree[i<<1|1];
        }
    }
    static int sum(int[]tree,int l,int r){
        int cnt=0;
        while(l<=r){
            if((l&1)!=0) cnt+=tree[l++];
            if((r&1)==0) cnt+=tree[r--];
            l>>=1;
            r>>=1;
        }
        return cnt;
    }

    static void minus(int[]tree,int x){
        while(x>0){
            tree[x]-=1;
            x>>=1;
        }
    }
    static void plus(int[]tree,int x){
        while(x>0){
            tree[x]+=1;
            x>>=1;
        }
    }

    public static void main(String[] args)throws Exception {
        int t=nextInt();
        while(t-->0){
            int n=nextInt(),m=nextInt();
            int[]arr = new int[n];
            for(int i=0;i<n;i++) arr[i]=n-i-1;
            int h = (int)Math.ceil(Math.log(n+m)/Math.log(2));
            int size = 1<<h;
            int[]tree = new int[size<<1];
            init(tree,n,size);

            int idx=n;
            while(m-->0){
                int x=nextInt();
                int k=sum(tree,size + arr[x-1],size+idx) - 1;
                write(k);
                minus(tree,size+arr[x-1]);
                arr[x-1]=idx++;
                plus(tree,size+arr[x-1]);
            }
            obuf[oidx++]='\n';
        }
        System.out.write(obuf,0,oidx);
    }
}
public class Main{
    static int iidx,isize;
    static byte[]ibuf = new byte[1<<23];
    static byte read()throws Exception{
        if(iidx==isize)
            isize=System.in.read(ibuf,iidx=0,1<<23);
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }

    static int oidx=0;
    static byte[]obuf = new byte[1<<17];
    static void write(long x){
        if(x==0){
            obuf[oidx++]='0';
            obuf[oidx++]='\n';
            return;
        }
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

    static int query(int[]tree,int[]arr,int s,int e,int size){
        int minidx=s;
        int minval = tree[s+size];
        s+=size;
        e+=size;
        while(s<=e){
            if((s&1)!=0){
                if(minval>tree[s]){
                    minidx=arr[s];
                    minval=tree[s];
                }
                s++;
            }
            if((e&1)==0){
                if(minval>tree[e]){
                    minidx=arr[e];
                    minval=tree[e];
                }
                e--;
            }
            s>>=1;
            e>>=1;
        }
        return minidx;
    }
    static long func(int[]tree,int[]arr,int s,int e,int size){
        if(s>e){
            return 0;
        }
        if(s==e) return tree[size+s];
        int minidx = query(tree,arr,s,e,size);
        long area = (long) tree[size + minidx] * (e-s+1);
        long left = func(tree,arr,s,minidx-1,size);
        long right = func(tree,arr,minidx+1,e,size);
        area = area>left?area:left;
        area=area>right?area:right;
        return area;
    }

    public static void main(String[] args)throws Exception{
        int n;
        while((n=nextInt())!=0){
            int h = (int)Math.ceil(Math.log(n)/Math.log(2));
            int size = 1<<h;
            int[]tree = new int[size<<1];
            int[]arr = new int[size<<1];
            for(int i=0;i<n;i++){
                tree[size+i]=nextInt();
                arr[size+i]=i;
            }
            for(int i=size-1;i>0;i--){
                if(tree[i<<1]<tree[i<<1|1]){
                    tree[i]=tree[i<<1];
                    arr[i]=arr[i<<1];
                }
                else{
                    tree[i]=tree[i<<1|1];
                    arr[i]=arr[i<<1|1];
                }
            }
            write(func(tree,arr,0,n-1,size));
        }
        System.out.write(obuf,0,oidx);
    }
}
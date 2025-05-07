    import java.util.ArrayList;
    public class Main{
        static int ISIZE = 1<<20;
        static int isize,iidx;
        static byte[]ibuf = new byte[ISIZE];
        static byte read()throws Exception{
            if(isize==iidx){
                isize = System.in.read(ibuf,iidx = 0,ISIZE);
            }
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
        static byte[]obuf = new byte[1<<20];
        static void write(int x){
            int s = oidx;
            while(x>0){
                obuf[oidx++]=(byte)(x%10+'0');
                x/=10;
            }
            int e = oidx-1;
            while(s<e){
                byte temp = obuf[s];
                obuf[s] = obuf[e];
                obuf[e] = temp;
                s++;
                e--;
            }
            obuf[oidx++]='\n';
        }

        static ArrayList<Integer>[]arr;
        static int[]par;
        static int[]depth;
        static void set(int node, int parent){
            par[node]=parent;
            depth[node]=depth[parent]+1;
            for(int i=0;i<arr[node].size();i++){
                if(arr[node].get(i)==parent) continue;
                set(arr[node].get(i),node);
            }
        }

        static int lca(int x,int y){
            while(depth[x]<depth[y]){
                y=par[y];
            }
            while(depth[x]>depth[y]){
                x=par[x];
            }
            while(x!=y){
                x=par[x];
                y=par[y];
            }
            return x;
        }
        public static void main(String[] args)throws Exception{
            int n = nextInt();
            arr = new ArrayList[n+1];
            par = new int[n+1];
            depth = new int[n+1];
            for(int i=0;i<=n;i++){
                arr[i] = new ArrayList<>();
            }
            for(int i=0;i<n - 1;i++) {
                int x = nextInt(), y = nextInt();
                arr[x].add(y);
                arr[y].add(x);
            }
            depth[0]=0;
            set(1,0);
            int m = nextInt();
            for(int i=0;i<m;i++){
                int x=nextInt(),y=nextInt();
                write(lca(x,y));
            }
            System.out.write(obuf,0,oidx);
        }
    }

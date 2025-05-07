import java.util.ArrayList;
public class Main{
    static final int ISIZE = 1<<20;
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
    static int[][]par;
    static int[]depth;
    static int h;
    static void set(int node, int parent){
        par[node][0]=parent;
        depth[node]=depth[parent]+1;
        for(int i=1;i<=h;i++){
            par[node][i] = par[par[node][i-1]][i-1];
        }
        for(int child:arr[node]){
            if(child==parent) continue;
            set(child,node);
        }
    }
    static int lca(int x,int y){
        if(x==1||y==1) return 1;
        if(depth[x]<depth[y]){
            int temp=x;
            x=y;
            y=temp;
        }
        int diff = depth[x] - depth[y];
        for(int i=h;i>=0;i--){
            if((diff&(1<<i))!=0){
                x = par[x][i];
            }
        }
        if(x==y) return x;
        for(int i=h;i>=0;i--){
            if(par[x][i]!=par[y][i]){
                x=par[x][i];
                y=par[y][i];
            }
        }
        return par[x][0];
    }
    public static void main(String[] args)throws Exception{
        int n = nextInt();
        h = (int)(Math.log(n) / Math.log(2)) + 1;
        arr = new ArrayList[n+1];
        par = new int[n+1][h+1];
        depth = new int[n+1];
        for(int i=0;i<=n;i++){
            arr[i] = new ArrayList<>();
        }
        for(int i=0;i<n - 1;i++) {
            int x = nextInt(), y = nextInt();
            arr[x].add(y);
            arr[y].add(x);
        }
        set(1,0);
        int m = nextInt();
        for(int i=0;i<m;i++){
            int x=nextInt(),y=nextInt();
            write(lca(x,y));
        }
        System.out.write(obuf,0,oidx);
    }
}
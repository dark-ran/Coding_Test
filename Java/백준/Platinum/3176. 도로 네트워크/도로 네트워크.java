import java.util.*;
public class Main{
    static final int ISIZE = 1<<22;
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
    }


    static final int MAX = 1000001;
    static int h,n;
    static ArrayList<Pair>[]arr;
    static int[][]par;
    static int[]depth;
    static int[][]minroad;
    static int[][]maxroad;

    static void parent(int node,int parent,int len){
        depth[node]=depth[parent]+1;
        par[node][0]=parent;
        minroad[node][0] =  maxroad[node][0] = len;
        for(Pair i : arr[node]){
            if(i.x!=parent)
                parent(i.x,node,i.y);
        }
    }

    static void set(){
        for(int i=1;i<h;i++){
            for(int j=1;j<=n;j++){
                if(par[j][i-1]!=0){
                    par[j][i]=par[par[j][i-1]][i-1];
                    minroad[j][i]=Math.min(minroad[par[j][i-1]][i-1],minroad[j][i-1]);
                    maxroad[j][i]=Math.max(maxroad[par[j][i-1]][i-1],maxroad[j][i-1]);
                }
            }
        }
    }

    static void lca(int a,int b){
        int min=MAX,max=0;
        if(depth[a]<depth[b]){
            int t = a;
            a=b;
            b=t;
        }
        int diff = depth[a]-depth[b];
        for(int i=0;i<h;i++){
            if((diff&(1<<i))!=0){
                min=Math.min(min,minroad[a][i]);
                max=Math.max(max,maxroad[a][i]);
                a=par[a][i];
            }
        }
        if(a==b){
            write(min);
            obuf[oidx++]=' ';
            write(max);
            obuf[oidx++]='\n';
            return;
        }
        for(int i=h-1;i>=0;i--){
            if(par[a][i]!=0&&par[a][i]!=par[b][i]){
                min = Math.min(min,Math.min(minroad[a][i],minroad[b][i]));
                max = Math.max(max,Math.max(maxroad[a][i],maxroad[b][i]));
                a=par[a][i];
                b=par[b][i];
            }
        }
        min = Math.min(min,Math.min(minroad[a][0],minroad[b][0]));
        max = Math.max(max,Math.max(maxroad[a][0],maxroad[b][0]));
        write(min);
        obuf[oidx++]=' ';
        write(max);
        obuf[oidx++]='\n';
    }

    public static void main(String[] args)throws Exception{
        n = nextInt();
        h = (int)(Math.log(n)/Math.log(2))+1;
        arr = new ArrayList[n+1];
        par = new int[n+1][h+1];
        depth = new int[n+1];
        minroad = new int[n+1][h];
        maxroad = new int[n+1][h];

        for(int i=0;i<=n;i++) {
            arr[i] = new ArrayList<>();
            for (int j = 0; j < h; j++) {
                minroad[i][j] = MAX;
            }
        }

        for(int i=1;i<n;i++){
            int a=nextInt(),b=nextInt(),c=nextInt();
            arr[a].add(new Pair(b,c));
            arr[b].add(new Pair(a,c));
        }


        parent(1,0,0);
        set();

        int k = nextInt();
        while(k-->0){
            int d =nextInt(),e=nextInt();
            lca(d,e);
        }
        System.out.write(obuf,0,oidx);
    }
}

class Pair{
    int x,y;
    Pair(int a,int b){
        x=a;
        y=b;
    }
}
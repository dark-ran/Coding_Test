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

    static final int OSIZE = 1<<13;
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

    static final int MAX = 1987654421;

    public static void main(String[] args)throws Exception {
        int n = nextInt(),m=nextInt();
        int[]arr = new int[n];
        ArrayList<Pair>[]li = new ArrayList[n];
        int[]prev = new int[n];
        boolean[]vis = new boolean[n];
        PriorityQueue<Pair>pq = new PriorityQueue<>(2 * n);
        for(int i=0;i<n;i++) {
            arr[i]=MAX;
            li[i]=new ArrayList<>();
            prev[i]=-1;
        }

        for(int i=0;i<m;i++){
            int x = nextInt()-1,y=nextInt()-1,z=nextInt();
            li[x].add(new Pair(y,z));
        }

        int start = nextInt()-1,end = nextInt()-1;
        pq.add(new Pair(0,start));
        arr[start]=0;
        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            if(vis[cur.y]) continue;
            vis[cur.y]=true;
            if(cur.y==end) break;
            for(Pair i:li[cur.y]){
                if(vis[i.x]||cur.x+i.y>=arr[i.x])continue;
                arr[i.x]=cur.x+i.y;
                prev[i.x]=cur.y;
                pq.add(new Pair(arr[i.x],i.x));
            }
        }
        write(arr[end]);
        obuf[oidx++]='\n';
        List<Integer>path = new ArrayList<>();
        int cur = end;
        while(cur!=-1){
            path.add(cur);
            cur=prev[cur];
        }
        write(path.size());
        obuf[oidx++]='\n';
        for(int i = path.size()-1;i>=0;i--){
            write(path.get(i)+1);
            obuf[oidx++]=' ';
        }
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
}

class Pair implements Comparable<Pair>{
    int x,y;
    Pair(int a,int b){
        x=a;
        y=b;
    }

    @Override
    public int compareTo(Pair o){
        if(this.x!=o.x) return this.x-o.x;
        return this.y-o.y;
    }
}
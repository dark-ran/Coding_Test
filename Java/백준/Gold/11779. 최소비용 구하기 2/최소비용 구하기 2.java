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
        ArrayList<int[]>[]li = new ArrayList[n];
        ArrayList<int[]>[]backli = new ArrayList[n];
        boolean[]vis = new boolean[n];
        PriorityQueue<Pair>pq = new PriorityQueue<>(n);
        for(int i=0;i<n;i++) {
            arr[i]=MAX;
            li[i]=new ArrayList<>();
            backli[i]=new ArrayList<>();
        }

        for(int i=0;i<m;i++){
            int x = nextInt()-1,y=nextInt()-1,z=nextInt();
            li[x].add(new int[]{y,z});
            backli[y].add(new int[]{x,z});
        }

        int start = nextInt()-1,end = nextInt()-1;
        pq.add(new Pair(0,start));
        arr[start]=0;
        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            if(vis[cur.y]) continue;
            vis[cur.y]=true;
            for(int[]i:li[cur.y]){
                if(vis[i[0]]||cur.x+i[1]>=arr[i[0]])continue;
                arr[i[0]]=cur.x+i[1];
                pq.add(new Pair(arr[i[0]],i[0]));
            }
        }
        write(arr[end]);
        obuf[oidx++]='\n';
        ArrayList<Integer>back = new ArrayList<>();
        int cur = end;
        back.add(cur);
        while(true){
            for(int[]i : backli[cur]){
                if(arr[cur]-i[1]==arr[i[0]]){
                    cur = i[0];
                    back.add(i[0]);
                    break;
                }
            }
            if(cur==start) break;
        }
        write(back.size());
        obuf[oidx++]='\n';
        for(int i = back.size()-1;i>=0;i--){
            write(back.get(i)+1);
            obuf[oidx++]=' ';
        }
        System.out.write(obuf,0,oidx);
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
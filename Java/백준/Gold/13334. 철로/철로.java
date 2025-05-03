import java.util.PriorityQueue;
import java.util.List;
import java.util.LinkedList;

public class Main{
    static int isize,iidx;
    static byte[]ibuf = new byte[1<<21];
    static byte read()throws Exception{
        if(isize==iidx){
            isize=System.in.read(ibuf,0,1<<21);
            iidx=0;
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())<' ');
        boolean flag = (c=='-');
        if(flag) c=read();
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=read())>='0');
        return flag?-n:n;
    }
    public static void main(String[] args)throws Exception{
        int n=nextInt();
        List<Pair>arr = new LinkedList<>();
        for(int i=0;i<n;i++){
            int x=nextInt(),y=nextInt();
            if(x>y){
                int temp=x;
                x=y;
                y=temp;
            }
            arr.add(new Pair(x,y));
        }
        int d=nextInt();
        PriorityQueue<Pair> pq = new PriorityQueue<>(n * 2, (a, b) -> {
            if (a.start != b.start) {
                return a.start - b.start;
            }
            return b.end - a.end;
        });
        for(Pair a:arr){
            if(a.end-a.start>d) continue;
            pq.add(new Pair(a.end - d,1));
            pq.add(new Pair(a.start,-1));
        }
        int res=0,cnt=0;
        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            cnt+=cur.end;
            res=res>cnt?res:cnt;
        }
        System.out.print(res);
    }
}

class Pair{
    int start,end;
    public Pair(int x,int y){
        this.start=x;
        this.end=y;
    }
}
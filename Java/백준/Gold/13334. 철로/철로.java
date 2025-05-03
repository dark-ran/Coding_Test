import java.util.PriorityQueue;
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
    static int oidx=0;
    static byte[]obuf=new byte[6];
    static void write(int x){
        if(x==0) {
            obuf[oidx++]='0';
            return;
        }
        while(x>0){
            obuf[oidx++]=(byte)((x % 10) + '0');
            x /= 10;
        }
        int s=0, e=oidx-1;
        while(s<e){
            byte c=obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=c;
            s++;
            e--;
        }
    }

    public static void main(String[] args)throws Exception{
        int n=nextInt();
        int[][]arr=new int[2][n];
        for(int i=0;i<n;i++){
            int x=nextInt(),y=nextInt();
            if(x>y){
                int temp=x;
                x=y;
                y=temp;
            }
            arr[0][i]=x;
            arr[1][i]=y;
        }
        int d=nextInt();
        PriorityQueue<Pair> pq = new PriorityQueue<>(n * 2, (a, b) -> {
            if (a.start != b.start) {
                return a.start - b.start;
            }
            return b.end - a.end;
        });
        for(int i=n-1;i>=0;i--){
            if(arr[1][i]-arr[0][i]>d) continue;
            pq.add(new Pair(arr[1][i] - d,1));
            pq.add(new Pair(arr[0][i],-1));
        }
        int res=0,cnt=0;
        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            cnt+=cur.end;
            res=res>cnt?res:cnt;
        }
        write(res);
        System.out.write(obuf,0,oidx);
    }
}

class Pair{
    int start,end;
    public Pair(int x,int y){
        this.start=x;
        this.end=y;
    }
}
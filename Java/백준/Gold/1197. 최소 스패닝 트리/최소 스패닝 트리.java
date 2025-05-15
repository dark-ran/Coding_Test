import java.util.*;
import java.io.*;

public class Main {
    static final int ISIZE = 1 << 21;
    static byte[] ibuf = new byte[ISIZE];
    static int iidx, isize;

    static byte read() throws IOException {
        if (iidx == isize) {
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        }
        return ibuf[iidx++];
    }

    static int nextInt() throws IOException {
        int n = 0;
        byte b;
        boolean flag = false;
        if((b=read())=='-'){
            flag = true;
            b=read();
        }
        do{
            n = (n << 3) + (n << 1) + (b & 15);
        }while ((b = read()) >= '0');
        return flag?-n:n;
    }

    static final int OSIZE = 1<<4;
    static byte[] obuf = new byte[OSIZE];
    static int oidx;

    static void write(long n) {
        if (n == 0) {
            obuf[oidx++] = '0';
            return;
        }
        if(n<0){
            n=-n;
            obuf[oidx++]='-';
        }
        int s = oidx;
        while (n > 0) {
            obuf[oidx++] = (byte)((n % 10) + '0');
            n /= 10;
        }
        int e = oidx - 1;
        while (s < e) {
            byte t = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = t;
            s++; e--;
        }
    }


    public static void main(String[] args) throws IOException {
        int v = nextInt(),e=nextInt();
        long sum = 0;
        boolean[]vis = new boolean[v];
        PriorityQueue<Pair>q = new PriorityQueue<>(e);
        ArrayList<Pair>[]li = new ArrayList[v];
        for(int i=0;i<v;i++) li[i]=new ArrayList<>();
        while(e-->0){
            int a = nextInt()-1,b=nextInt()-1,c=nextInt();
            li[a].add(new Pair(b,c));
            li[b].add(new Pair(a,c));
        }
        q.add(new Pair(0,0));
        while(!q.isEmpty()){
            Pair cur = q.poll();
            if(vis[cur.x]) continue;
            vis[cur.x]=true;
            sum+=cur.y;
            for(Pair a : li[cur.x]){
                if(vis[a.x]) continue;
                q.add(a);
            }
        }
        write(sum);
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
    public int compareTo(Pair o){
        return this.y-o.y;
    }
}
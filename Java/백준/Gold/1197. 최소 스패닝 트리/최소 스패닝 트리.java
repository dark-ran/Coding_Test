import java.util.*;
import java.io.*;

public class Main {
    static final int ISIZE = 1 << 23;
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


    static int[]parent;
    static int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    static boolean union(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        parent[b]=a;
        return true;
    }

    public static void main(String[] args) throws IOException {
        int v = nextInt(),e=nextInt();
        parent=new int[v];
        for(int i=0;i<v;i++) parent[i]=i;

        PriorityQueue<Trio>pq = new PriorityQueue<>(e);
        while(e-->0){
            int a = nextInt()-1,b=nextInt()-1,c=nextInt();
            pq.add(new Trio(a,b,c));
        }
        long sum = 0;
        while(!pq.isEmpty()){
            Trio cur = pq.poll();
            if(union(cur.x,cur.y)){
                sum+=cur.z;
            }
        }
        write(sum);
        System.out.write(obuf,0,oidx);
        System.out.flush();
    }
}

class Trio implements Comparable<Trio>{
    int x,y,z;
    Trio(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
    public int compareTo(Trio o){
        return this.z-o.z;
    }
}
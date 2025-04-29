import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
public class Main{
    static int size,iidx;
    static byte[]ibuf=new byte[1<<8];
    static StringBuilder obuf = new StringBuilder();

    static byte read()throws Exception{
        if(size==iidx){
            size=System.in.read(ibuf,iidx=0,1<<8);
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while('0'<=(c=read()));
        return n;
    }
    static String nextStr()throws Exception{
        StringBuilder sb=new StringBuilder();
        byte c;
        while((c=read())<'A');
        do{
            sb.append((char)c);
        }while((c=read())>='A');
        return sb.toString();
    }

    static class Trie{
        Map<String,Trie> child=new HashMap<>();
        public void insert()throws Exception{
            Trie trie = this;
            int x=nextInt();
            for(int i=0;i<x;i++) {
                String str = nextStr();
                if(!trie.child.containsKey(str)){
                    trie.child.put(str,new Trie());
                }
                trie=trie.child.get(str);
            }
        }
    }
    public static void print(Trie cur,int idx){
        Trie trie = cur;
        if(trie.child!=null){
            ArrayList<String>list=new ArrayList<>(trie.child.keySet());
            Collections.sort(list);
            for(String str:list) {
                for(int i=0;i<idx;i++) obuf.append("--");
                obuf.append(str).append('\n');
                print(cur.child.get(str),idx+1);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        int N=nextInt();
        Trie root = new Trie();
        for(int i=0;i<N;i++){
            root.insert();
        }
        print(root,0);
        System.out.print(obuf);
    }
}
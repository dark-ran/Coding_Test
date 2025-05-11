import java.util.*;
public class Main {
    static int ISIZE = 1<<27;
    static int iidx, isize;
    static final byte[] ibuf = new byte[ISIZE];
    static byte read() throws Exception {
        if (iidx == isize)
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        return ibuf[iidx++];
    }
    static int nextInt() throws Exception {
        int n = 0;
        byte c;
        while ((c = read()) >= '0'){
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }
    static String nextStr()throws Exception{
        StringBuilder sb = new StringBuilder();
        byte b;
        while((b=read())>='a'){
            sb.append((char)b);
        }
        return sb.toString();
    }

    static final int OSIZE = 1<<20;
    static int oidx = 0;
    static final byte[] obuf = new byte[OSIZE];
    static void write(boolean x){
        if(x){
            obuf[oidx++]='Y';
            obuf[oidx++]='e';
            obuf[oidx++]='s';
            obuf[oidx++]='\n';
        }
        else{
            obuf[oidx++]='N';
            obuf[oidx++]='o';
            obuf[oidx++]='\n';
        }
    }
    static class TrieNode {
        TrieNode[] child;
        boolean isend;

        TrieNode() {
            child = new TrieNode[26];
            isend = false;
        }
    }
    static class Trie{
        TrieNode root;
        Trie(){
            this.root = new TrieNode();
        }
    }
    static boolean check(String s){
        TrieNode temp = colorTrie.root;
        int l = s.length();
        for(int i=0;i<l;i++){
            char c = s.charAt(i);
            if(temp.child[c-'a']==null)
                return false;
            temp = temp.child[c-'a'];
            if(temp.isend&&name.contains(s.substring(i+1)))
                return true;
        }
        return false;
    }

    static Set<String> name =new HashSet<>();
    static Trie colorTrie =new Trie();

    public static void main(String[] args) throws Exception {
        int n=nextInt(),m=nextInt();
        while (n-- > 0) {
            String s= nextStr();
            TrieNode temp = colorTrie.root;
            for(char a : s.toCharArray()){
                if(temp.child[a-'a']==null)
                    temp.child[a-'a']=new TrieNode();
                temp = temp.child[a-'a'];
            }
            temp.isend = true;
        }
        while (m-- > 0) {
            name.add(nextStr());
        }
        int q = nextInt();
        while(q-->0){
            String s = nextStr();
            write(check(s));
        }
        System.out.write(obuf,0,oidx);
    }
}

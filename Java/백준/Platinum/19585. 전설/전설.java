import java.io.*;
import java.util.*;
public class Main {
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

    static StringBuilder sb=new StringBuilder();
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Set<String> name =new HashSet<>();
    static Trie colorTrie =new Trie();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        while (n-- > 0) {
            String s= br.readLine();
            TrieNode temp = colorTrie.root;
            for(char a : s.toCharArray()){
                if(temp.child[a-'a']==null)
                    temp.child[a-'a']=new TrieNode();
                temp = temp.child[a-'a'];
            }
            temp.isend = true;
        }
        while (m-- > 0) {
            name.add(br.readLine());
        }
        int q = Integer.parseInt(br.readLine());
        while(q-->0){
            String s = br.readLine();
            if(check(s))
                sb.append("Yes\n");
            else
                sb.append("No\n");
        }
        System.out.print(sb);
    }
}

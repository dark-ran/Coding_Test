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
    
    static class Trie {
        TrieNode root;
        Trie() {
            this.root = new TrieNode();
        }
        
        void insert(String s) {
            TrieNode temp = root;
            for(char c : s.toCharArray()) {
                if(temp.child[c-'a'] == null) {
                    temp.child[c-'a'] = new TrieNode();
                }
                temp = temp.child[c-'a'];
            }
            temp.isend = true;
        }
        
        boolean hasPrefix(String s) {
            TrieNode temp = root;
            for(char c : s.toCharArray()) {
                if(temp.child[c-'a'] == null) return false;
                temp = temp.child[c-'a'];
            }
            return true;
        }
    }
    
    static class SimpleHashSet {
        private static final int DEFAULT_CAPACITY = 1 << 16;
        private static final float LOAD_FACTOR = 0.75f;
        
        private String[] table;
        private int size;
        private int threshold;
        
        public SimpleHashSet() {
            table = new String[DEFAULT_CAPACITY];
            threshold = (int)(DEFAULT_CAPACITY * LOAD_FACTOR);
        }
        
        public void add(String key) {
            if(size >= threshold) resize();
            
            int hash = hash(key);
            int index = hash & (table.length - 1);
            
            while(table[index] != null) {
                if(table[index].equals(key)) return;
                index = (index + 1) & (table.length - 1);
            }
            
            table[index] = key;
            size++;
        }
        
        public boolean contains(String key) {
            int hash = hash(key);
            int index = hash & (table.length - 1);
            
            while(table[index] != null) {
                if(table[index].equals(key)) return true;
                index = (index + 1) & (table.length - 1);
            }
            
            return false;
        }
        
        private void resize() {
            String[] oldTable = table;
            table = new String[table.length << 1];
            threshold <<= 1;
            size = 0;
            
            for(String key : oldTable) {
                if(key != null) add(key);
            }
        }
        
        private int hash(String key) {
            int h = key.hashCode();
            return h ^ (h >>> 16);
        }
    }
    
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static SimpleHashSet nameSet = new SimpleHashSet();
    static Trie colorTrie = new Trie();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        // 색상 이름 트라이 구성
        while (n-- > 0) {
            colorTrie.insert(br.readLine());
        }
        
        // 팀 이름 해시셋 구성
        while (m-- > 0) {
            nameSet.add(br.readLine());
        }
        
        // 쿼리 처리
        int q = Integer.parseInt(br.readLine());
        while(q-- > 0) {
            String s = br.readLine();
            sb.append(check(s) ? "Yes\n" : "No\n");
        }
        
        System.out.print(sb);
    }
    
    static boolean check(String s) {
        TrieNode temp = colorTrie.root;
        int l = s.length();
        
        for(int i = 0; i < l; i++) {
            char c = s.charAt(i);
            if(temp.child[c-'a'] == null) return false;
            temp = temp.child[c-'a'];
            if(temp.isend && nameSet.contains(s.substring(i+1))) {
                return true;
            }
        }
        return false;
    }
}
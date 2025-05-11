import java.io.*;
import java.util.*;

public class Main {
    static class TrieNode {
        TrieNode[] children;
        boolean isEnd;

        TrieNode() {
            children = new TrieNode[26];
            isEnd = false;
        }
    }

    static TrieNode colorRoot = new TrieNode();
    static Set<String> names = new HashSet<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        // 색상 이름을 트라이에 추가
        for (int i = 0; i < C; i++) {
            String color = br.readLine();
            TrieNode current = colorRoot;
            for (char c : color.toCharArray()) {
                int idx = c - 'a';
                if (current.children[idx] == null) {
                    current.children[idx] = new TrieNode();
                }
                current = current.children[idx];
            }
            current.isEnd = true;
        }

        // 팀 이름을 HashSet에 추가
        for (int i = 0; i < N; i++) {
            names.add(br.readLine());
        }

        int Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            String team = br.readLine();
            sb.append(checkLegend(team) ? "Yes\n" : "No\n");
        }

        System.out.print(sb);
    }

    static boolean checkLegend(String team) {
        TrieNode current = colorRoot;
        for (int i = 0; i < team.length(); i++) {
            char c = team.charAt(i);
            int idx = c - 'a';
            
            if (current.children[idx] == null) {
                return false;
            }
            
            current = current.children[idx];
            if (current.isEnd && names.contains(team.substring(i + 1))) {
                return true;
            }
        }
        return false;
    }
}
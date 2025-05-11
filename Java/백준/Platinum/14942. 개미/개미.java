import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] energy;
    static List<List<Edge>> graph = new ArrayList<>();
    static int[] parent;
    static int[] answer;

    static class Edge {
        int to, cost;

        Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        energy = new int[N + 1];
        parent = new int[N + 1];
        answer = new int[N + 1];

        for (int i = 1; i <= N; i++) energy[i] = Integer.parseInt(br.readLine());

        for (int i = 0; i <= N; i++) graph.add(new ArrayList<>());

        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph.get(a).add(new Edge(b, cost));
            graph.get(b).add(new Edge(a, cost));
        }

        dfs(1, 0);

        for(int i = N; 0 < i; i--) answer[i] = process(i, energy[i]);

        for(int i = 1; i <= N; i++) System.out.println(answer[i]);
    }

    static void dfs(int node, int parentNode) {
        parent[node] = parentNode;
        for (Edge edge : graph.get(node))
            if (edge.to != parentNode) dfs(edge.to, node);
    }

    static int process(int node, int hp){
        int cur = node;
        while(cur != 1){
            int parentNode = parent[cur];
            int nextCost = 0;
            for(Edge edge : graph.get(cur)){
                if(edge.to == parentNode){
                    nextCost = edge.cost; break;
                }
            }
            if(hp < nextCost) return cur;
            hp -= nextCost;
            cur = parentNode;
        }
        return 1;
    }
}

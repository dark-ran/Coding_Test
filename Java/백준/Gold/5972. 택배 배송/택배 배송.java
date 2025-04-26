import java.util.ArrayList;
import java.util.PriorityQueue;
public class Main{
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=System.in.read())>='0');
        return n;
    }
    private static class Edge implements Comparable<Edge>{
        int end, data;

        Edge(int x, int y) {
            this.end = x;
            this.data = y;
        }
        @Override
        public int compareTo(Edge o){
            return Integer.compare(this.data,o.data);
        }
    }
    static ArrayList<Edge>[]arr;
    static int[]cost;
    static int INF = 1987654321;
    public static void main(String[]args)throws Exception{
        int n=read(),m=read();
        arr=new ArrayList[n+1];
        for(int i=0;i<=n;i++) arr[i]=new ArrayList<>();
        cost=new int[n+1];
        for(int i=0;i<m;i++){
            int a=read(),b=read(),c=read();
            arr[a].add(new Edge(b,c));
            arr[b].add(new Edge(a,c));
        }

        for(int i=1;i<=n;i++){
            cost[i]=INF;
        }
        Dijkstra(n);
        System.out.print(cost[n]);
    }
    static void Dijkstra(int n) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[n + 1];
        pq.add(new Edge(1, 0));
        cost[1] = 0;

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (visited[cur.end]) continue;
            visited[cur.end] = true;

            for (Edge next : arr[cur.end]) {
                if (!visited[next.end] && cost[next.end] > cost[cur.end] + next.data) {
                    cost[next.end] = cost[cur.end] + next.data;
                    pq.add(new Edge(next.end, cost[next.end]));
                }
            }
        }
    }
}
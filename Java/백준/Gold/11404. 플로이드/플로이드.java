public class Main{
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=System.in.read())>='0');
        return n;
    }
    public static void main(String[]args)throws Exception{
        int INF = 0x3f3f3f3f;
        int n=read(),m=read();
        int[][]cost=new int[n+1][n+1];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) cost[i][j]=INF;
            cost[i][i]=0;
        }
        for(int i=0;i<m;i++) {
            int a = read(), b = read(), c = read();
            cost[a][b] = Integer.min(cost[a][b], c);
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    cost[i][j]=Integer.min(cost[i][j],cost[i][k]+cost[k][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]==INF) System.out.print(0);
                else System.out.print(cost[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

}
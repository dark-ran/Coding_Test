public class Main {
    static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) >= 48) {
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }
    public static void main(String[] args) throws Exception {
        int n = read(), k = read();
        int[] arr = new int[n + 1];
        boolean[]vis = new boolean[100001];
        int[] dp = new int[k+1];
        for(int i=1;i<=k;i++) dp[i] = 2000000000;
        int idx=0;
        for (int i = 0; i < n; i++) {
            int x=read();
            if(!vis[x] && x<=k){
                arr[idx++]=x;
                vis[x]=true;
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<idx;j++){
                if(i+arr[j]<=k)dp[i+arr[j]]=dp[i]+1<dp[i+arr[j]]?dp[i]+1:dp[i+arr[j]];
            }
        }
        System.out.print(dp[k]==2000000000?-1:dp[k]);
    }
}
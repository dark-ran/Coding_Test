	public class Main {
        static int read() throws Exception {
            int c, n = System.in.read() & 15;
            boolean m = n == 13;
            if (m)n = System.in.read() & 15;
            while ((c = System.in.read()) >= 48) {
            n = (n << 3) + (n << 1) + (c & 15);}
            return m ? ~n + 1 : n;
        }
		public static void main(String[] args) throws Exception {
			int n = read();
			int dp[][] = new int[n+1][n+1];

			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					dp[i][j] = read() + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

			int Max = -1001;
			for(int size=1; size<=n; size++){
				for(int i=0; i+size<=n; i++){
					for(int j=0; j+size<=n; j++){
						int cnt = dp[i+size][j+size]-dp[i+size][j]-dp[i][j+size]+dp[i][j];
						Max=Max>cnt?Max:cnt;
					}
				}
			}

			System.out.print(Max);
		}
		
	}
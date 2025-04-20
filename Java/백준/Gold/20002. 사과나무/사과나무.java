import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
 
public class Main {
	static int[][] dp = new int[301][301];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine();
		int n = Integer.parseInt(s);
		for(int i=1; i<=n; i++){
			String[] row=br.readLine().split(" ");
			for(int j=1; j<=n; j++){
				dp[i][j]=Integer.parseInt(row[j-1]) + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
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
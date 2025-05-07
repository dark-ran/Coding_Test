public class Main{
    static final int MOD = 10007;
    static final int ISIZE = 1<<10;
    static int isize,iidx;
    static byte[]ibuf = new byte[ISIZE];
    static byte read()throws Exception{
        if(isize==iidx){
            isize = System.in.read(ibuf,iidx=0,ISIZE);
        }
        return ibuf[iidx++];
    }
    static char[] nextStr()throws Exception{
        StringBuilder sb = new StringBuilder();
        byte c;
        while((c=read())!='\n'){
            sb.append((char)c);
        }
        return sb.toString().toCharArray();
    }
    static int oidx = 0;
    static byte[]obuf = new byte[10];
    static void write(int x){
        if(x==0){
            obuf[oidx++]='0';
            return;
        }
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int s=0,e=oidx-1;
        while(s<e){
            byte t=obuf[s];
            obuf[s]=obuf[e];
            obuf[e]=t;
            s++;
            e--;
        }
    }

    public static void main(String[] args)throws Exception{
        char[] arr = nextStr();
        int n = isize-1;
        int[][]dp = new int[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                if(arr[j]==arr[i]){
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]+1)%MOD;
                }
                else{
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%MOD;
                    if(dp[i][j]<0) dp[i][j]+=MOD;
                }
            }
        }
        write(dp[0][n-1]%MOD);
        System.out.write(obuf,0,oidx);
    }
}
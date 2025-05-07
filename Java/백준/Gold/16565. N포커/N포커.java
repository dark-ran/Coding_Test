public class Main{
    static int MOD = 10007;
    static int isize,iidx;
    static byte[]ibuf = new byte[3];
    static byte read()throws Exception{
        if(iidx==isize){
            isize=System.in.read(ibuf,0,2);
            iidx=0;
        }
        return ibuf[iidx++];
    }
    static int oidx=0;
    static byte[]obuf = new byte[5];
    static void write(int x){
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int s=0,e=oidx-1;
        while(s<e){
            byte temp = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = temp;
            s++;
            e--;
        }
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    public static void main(String[] args)throws Exception{
        int n=nextInt();
        int[][]comb = new int[53][53];
        for(int i=0;i<=52;i++){
            comb[i][0] =  1;
            for(int j=1;j<=i;j++){
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
        if(n<4){
            obuf[0]='0';
            System.out.write(obuf,0,1);
            return;
        }
        if(n>48){
            write(comb[52][52-n]);
            System.out.write(obuf,0,oidx);
            return;
        }
        int sum=0;
        for(int i=1;i * 4 <= n && i <= 13;i++){
            sum=(sum + (i%2==1?1:-1) * comb[13][i] * comb[52-4*i][n-4*i]) % MOD;
        }
        if(sum<0) sum+=MOD;
        write(sum);
        System.out.write(obuf,0,oidx);
    }
}
public class Main{
    final static int MOD = 1000000007;
    static int iidx,isize;
    static byte[]ibuf = new byte[1<<23];
    static byte read()throws Exception{
        if(isize==iidx){
            isize = System.in.read(ibuf,iidx = 0,1<<23);
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    static int oidx = 0;
    static byte[]obuf = new byte[1<<17];
    static void write(long x){
        if(x==0) {
            obuf[oidx++]='0';
            obuf[oidx++]='\n';
            return;
        }
        int s=oidx;
        while(x>0){
            obuf[oidx++]=(byte)(x%10+'0');
            x/=10;
        }
        int e = oidx - 1;
        while(s<e){
            byte temp = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = temp;
            s++;
            e--;
        }
        obuf[oidx++]='\n';
    }

    public static void main(String[]args)throws Exception{
        int n=nextInt(),m=nextInt(),k=nextInt();
        int h = 32 - Integer.numberOfLeadingZeros(n-1);
        int size = 1<<h;
        long arr[] = new long[size<<1];
        for(int i=0;i<n;i++){
            arr[size+i]=nextInt();
        }
        for(int i=n;i<size;i++){
            arr[size+i]=1;
        }
        for(int i=size - 1;i>0;i--){
            arr[i] = arr[i<<1] * arr[i<<1|1] % MOD;
        }
        for(int i=m+k;i>0;i--){
            int a=nextInt(),b=nextInt(),c=nextInt();
            if(a == 1){
                int idx = size + b - 1;
                arr[idx] = c;
                while((idx>>>=1)>0){
                    long val = arr[idx<<1]*arr[idx<<1|1] % MOD;
                    if(val == arr[idx]) break;
                    arr[idx] = val;

                }
            }
            else{
                long sum = 1;
                int l = size + b - 1, r = size + c - 1;
                while(l<=r){
                    if((l&1)!=0)
                        sum = (sum * arr[l++]) % MOD;
                    if((r&1)==0)
                        sum = (sum * arr[r--]) % MOD;
                    l>>>=1;
                    r>>>=1;
                }
                write(sum);
            }
        }
        System.out.write(obuf,0,oidx);
    }
}
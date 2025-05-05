public class Main{
    static int MOD = 1000000007;
    static int iidx,isize;
    static byte[]ibuf = new byte[1<<37];
    static byte read()throws Exception{
        if(isize==iidx){
            isize = System.in.read(ibuf,0,1<<37);
            iidx=0;
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
    static Three input()throws Exception{
        int a=nextInt();
        int b=nextInt();
        int c=nextInt();
        return new Three(a,b,c);
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
        Three a = input();
        int h = (int)Math.ceil(Math.log(a.x)/Math.log(2));
        int size = 1<<h;
        long arr[] = new long[size<<1];
        for(int i=0;i<a.x;i++){
            arr[size+i]=nextInt();
        }
        for(int i=a.x;i<size;i++){
            arr[size+i]=1;
        }
        for(int i=size - 1;i>0;i--){
            arr[i] = arr[i<<1] * arr[(i<<1)+1] % MOD;
        }
        for(int i=a.y+a.z;i>0;i--){
            Three b = input();
            if(b.x == 1){
                int idx = size + b.y - 1;
                arr[idx] = b.z;
                idx>>=1;
                while(idx>0){
                    arr[idx] = arr[idx<<1]*arr[(idx<<1)+1] % MOD;
                    idx>>=1;
                }
            }
            else{
                long sum = 1;
                int l = size + b.y - 1, r = size + b.z - 1;
                while(l<=r){
                    if((l&1)!=0)
                        sum = (sum * arr[l++]) % MOD;
                    if((r&1)==0)
                        sum = (sum * arr[r--]) % MOD;
                    l>>=1;
                    r>>=1;
                }
                write(sum);
            }
        }
        System.out.write(obuf,0,oidx);
    }
}
class Three{
    int x,y,z;
    Three(int i,int j,int k){
        this.x=i;
        this.y=j;
        this.z=k;
    }
}
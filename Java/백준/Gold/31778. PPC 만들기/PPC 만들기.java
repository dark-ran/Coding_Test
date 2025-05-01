public class Main{
    static byte[]ibuf = new byte[1<<15];
    static int size,iidx;
    static byte ReadByte()throws Exception{
        if(size==iidx){
            size=System.in.read(ibuf,0,1<<15);
            iidx=0;
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n=0;
        byte c;
        while((c=ReadByte())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=ReadByte())>='0');
        return n;
    }
    static void nextStr(char[]arr)throws Exception{
        byte c;
        while((c=ReadByte())<'A');
        int i=0;
        do{
            arr[i++]=(char)c;
        }while((c=ReadByte())>='A');
    }
    public static void main(String[] args) throws Exception {
        int n=nextInt(),k=nextInt();
        char[]arr = new char[n];
        nextStr(arr);
        int s=0,e=n-1;
        while(s<e && k>0){
            while(s<n&&arr[s]=='P')s++;
            while(e>0&&arr[e]=='C')e--;
            if(s==n||e==-1) break;
            if(s<e){
                k--;
                arr[s]='P';
                arr[e]='C';
            }
        }
        long p=0,psum=0,res=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='P') psum+=p++;
            else res+=psum;
        }
        System.out.print(res);
    }
}
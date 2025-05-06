public class Main {
    static int isize,iidx;
    static byte[] ibuf = new byte[1<<17];
    static byte read()throws Exception{
        if(isize==iidx){
            isize = System.in.read(ibuf,iidx = 0,1<<17);
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
    static byte[]obuf = new byte[1<<20];
    static void write(int x){
        int s = oidx;
        while(x>0){
            obuf[oidx++] = (byte)(x%10+'0');
            x/=10;
        }
        int e = oidx-1;
        while(s<e){
            byte temp = obuf[s];
            obuf[s] = obuf[e];
            obuf[e] = temp;
            s++;
            e--;
        }
        obuf[oidx++] = '\n';
    }

    static void modify(int[]arr,int[]tree,int b, int c, int size){
        int idx = size + b;
        arr[b] = c;
        idx>>>=1;
        while(idx>0){
            tree[idx] = arr[tree[idx<<1]]<=arr[tree[idx<<1|1]]?tree[idx<<1]:tree[idx<<1|1];
            idx>>>=1;
        }
    }
    static void find(int[]arr,int[]tree,int b,int c,int size, int n){
        int l = size+b, r = size+c;
        int min = n;
        while(l<=r){
            if((l&1)!=0) {
                if(arr[min] == arr[tree[l]])
                    min=min<tree[l]?min:tree[l];
                else min = arr[tree[l]]<arr[min]?tree[l]:min;
            }
            if((r&1)==0) {
                if(arr[min] == arr[tree[r]])
                    min=min<tree[r]?min:tree[r];
                else min = arr[tree[r]]<arr[min]?tree[r]:min;
            }
            l++;
            r--;
            l>>>=1;
            r>>>=1;
        }
        write(min + 1);
    }
    public static void main(String[] args)throws Exception {
        int n=nextInt();
        int h = 32 - Integer.numberOfLeadingZeros(n-1);
        int size = 1<<h;
        int[] tree = new int[size<<1];
        int[] arr = new int[n + 1];
        for(int i=0;i<n;i++){
            arr[i] = nextInt();
            tree[i+size] = i;
        }
        for(int i=n;i<size;i++){
            tree[i+size] = n;
        }
        arr[n] = 1234567890;
        for(int i=size-1;i>0;i--){
            tree[i] = arr[tree[i<<1]]<=arr[tree[i<<1|1]]?tree[i<<1]:tree[i<<1|1];
        }
        int m =  nextInt();
        for(int i=0;i<m;i++){
            int a = nextInt(), b = nextInt(), c = nextInt();
            if(a==1){
                modify(arr,tree,b - 1,c, size);
            }
            else{
                find(arr,tree,b-1,c-1,size,n);
            }
        }
        System.out.write(obuf,0,oidx);
    }
}
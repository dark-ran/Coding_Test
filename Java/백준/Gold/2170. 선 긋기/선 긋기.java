import java.util.Arrays;
public class Main{
    static int isize,iidx;
    static byte[]ibuf = new byte[1<<16];
    static byte read()throws Exception{
        if(isize==iidx) {
            isize = System.in.read(ibuf, iidx = 0, 1 << 16);
        }
        return ibuf[iidx++];
    }
    static int nextInt() throws Exception {
        int n=0;
        byte c;
        boolean flag = false;
        while((c=read())<'-');
        if(c=='-') {
            flag = true;
            c=read();
        }
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=read())>='0');
        return flag ? -n : n;
    }
    public static void main(String[]args)throws Exception{
        int N = nextInt();
        int[][]arr=new int[N][2];
        for(int i=0;i<N;i++){
            arr[i][0]=nextInt();
            arr[i][1]=nextInt();
        }
        Arrays.sort(arr, (o1, o2) -> {
            return o1[0]-o2[0];
        });
        int sum=0,start = arr[0][0],end = arr[0][1];
        for(int i=1;i<N;i++){
            if(arr[i][0]<=end){
                if(end<arr[i][1]) end=arr[i][1];
            }
            else{
                sum+=end-start;
                start=arr[i][0];
                end=arr[i][1];
            }
        }
        sum+=end-start;
        System.out.print(sum);
    }
}
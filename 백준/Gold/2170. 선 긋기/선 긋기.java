import java.util.Arrays;
import java.util.Comparator;
public class Main{
    static int read() throws Exception {
        int c, n = 0;
        boolean negative = false;
        while ((c = System.in.read()) < '0') // 숫자 또는 '-'가 나올 때까지 건너뜀
            if (c == '-') negative = true;
        do n = (n << 3) + (n << 1) + (c & 15); // n = n * 10 + (c - '0')
        while ((c = System.in.read()) >= '0');
        return negative ? -n : n;
    }
    public static void main(String[]args)throws Exception{
        int N = read();
        int[][]arr=new int[N][2];
        for(int i=0;i<N;i++){
            arr[i][0]=read();
            arr[i][1]=read();
        }
        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));
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
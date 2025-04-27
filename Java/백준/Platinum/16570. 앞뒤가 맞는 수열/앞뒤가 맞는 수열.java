public class Main{
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    static void reverse(int[]a,int n){
        int start=0;
        int end=n-1;
        while(start<end){
            int temp=a[end];
            a[end]=a[start];
            a[start]=temp;
            start++;
            end--;
        }
    }
    public static void main(String[]args)throws Exception{
        int n=read();
        int[]arr=new int[n];
        for(int i=0;i<n;i++)arr[i]=read();
        reverse(arr,n);
        int[]f=new int[n];
        int MAX=0;
        int cnt=0;
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0&&arr[i]!=arr[j]){
                j=f[j-1];
            }
            if(arr[i]==arr[j]) {
                f[i] = ++j;
                if (f[i] > MAX) {
                    cnt = 1;
                    MAX = f[i];
                }
                else if (f[i] == MAX) {
                    cnt++;
                }
            }
        }
        if(cnt==0){
            System.out.print("-1");
            return;
        }
        System.out.print(MAX);
        System.out.print(' ');
        System.out.print(cnt);
    }
}
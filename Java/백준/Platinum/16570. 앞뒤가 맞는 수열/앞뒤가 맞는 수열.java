public class Main{
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    public static void main(String[]args)throws Exception{
        int n=read();
        int[]arr=new int[n];
        for(int i=0;i<n;i++)arr[i]=read();
        int[]f=new int[n];
        int MAX=0, cnt=0;
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0&&arr[n-1-i]!=arr[n-1-j]){
                j=f[j-1];
            }
            if(arr[n-1-i]==arr[n-1-j]) {
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
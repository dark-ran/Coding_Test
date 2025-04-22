public class Main {
    static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) >= 48) {
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }
    public static void quicksort(int[]arr,int start,int end){
        int part=partition(arr,start,end);
        if(start<part-1) quicksort(arr,start,part-1);
        if(part<end) quicksort(arr,part,end);
    }
    private static int partition(int[]arr,int start,int end){
        int pivot = arr[(start+end)>>1];
        while(start<=end){
            while(arr[start]<pivot)start++;
            while(arr[end]>pivot)end--;
            if(start<=end){
                swap(arr,start,end);
                start++;
                end--;
            }
        }
        return start;
    }
    private static void swap(int[]arr,int start,int end){
        int tmp=arr[start];
        arr[start]=arr[end];
        arr[end]=tmp;
    }

    public static void main(String[] args) throws Exception {
        int n = read(), k = read();
        int[] arr = new int[n + 1];
        boolean[]vis = new boolean[100001];
        int[] dp = new int[k+1];
        for(int i=1;i<=k;i++) dp[i] = 2000000000;
        int idx=0;
        for (int i = 0; i < n; i++) {
            int x=read();
            if(!vis[x] && x<=k){
                arr[idx++]=x;
                vis[x]=true;
                dp[x]=1;
            }
        }
        quicksort(arr,0,idx - 1);
        for(int i=1;i<k;i++){
            if(dp[i]!=0){
                for(int j=0;j<idx;j++){
                    if(i+arr[j]>k) break;
                    if(dp[i+arr[j]]==0) dp[i+arr[j]]=dp[i]+1;
                    else dp[i+arr[j]]=dp[i]+1<dp[i+arr[j]]?dp[i]+1:dp[i+arr[j]];
                }
            }
        }
        System.out.print(dp[k]==2000000000?-1:dp[k]);
    }
}
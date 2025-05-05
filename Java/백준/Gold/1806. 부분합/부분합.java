public class Main {
    static int read() throws Exception {
        int c, n = 0;
        while ((c = System.in.read()) >= 48) {
            n = (n << 3) + (n << 1) + (c & 15);
        }
        return n;
    }

    public static void main(String[] args) throws Exception {
        int n = read(), s = read();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = read() + arr[i - 1];
        }

        int cnt = 100001;
        int left = 0;
        for (int right = 1; right <= n; right++) {
            while (arr[right] - arr[left] >= s) {
                cnt=cnt<right-left?cnt:right-left;
                left++;
            }
        }
        System.out.print(cnt==100001?0:cnt);
    }
}
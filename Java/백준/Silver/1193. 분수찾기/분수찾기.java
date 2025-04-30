public class Main {
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())>='0'){
            n=(n<<3)+(n<<1)+(c&15);
        }
        return n;
    }
    public static void main(String[] args) throws Exception{
        int n=read();
        int cross_count = 1, prev_count_sum = 0;
        while (true) {
            if (n <= prev_count_sum + cross_count) {
                if (cross_count % 2 == 1) {
                    System.out.print((cross_count - (n - prev_count_sum - 1)) + "/" + (n - prev_count_sum));
                    break;
                }

                else {
                    System.out.print((n - prev_count_sum) + "/" + (cross_count - (n - prev_count_sum - 1)));
                    break;
                }

            } else {
                prev_count_sum += cross_count;
                cross_count++;
            }
        }
    }
}
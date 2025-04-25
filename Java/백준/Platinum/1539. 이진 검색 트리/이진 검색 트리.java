import java.util.TreeSet;

public class Main {
    static int read()throws Exception{
        int c,n=0;
        while((c=System.in.read())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=System.in.read())>='0');
        return n;
    }

    public static void main(String[] args) throws Exception {
        int n=read();
        int[] len = new int[n];
        long ans = 0;
        TreeSet<Integer> tree = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            int num = read();
            if (tree.higher(num) == null) {
                if (tree.lower(num) == null) {
                    len[num] = 1;
                } else {
                    len[num] = len[tree.lower(num)]+1;
                }
            } else {
                if (tree.lower(num) == null) {
                    len[num] = len[tree.higher(num)] + 1;
                } else {
                    len[num] =(len[tree.higher(num)]>len[tree.lower(num)]?len[tree.higher(num)]:len[tree.lower(num)])+1;
                }
            }
            ans += len[num];
            tree.add(num);
        }
        System.out.print(ans);
    }
}
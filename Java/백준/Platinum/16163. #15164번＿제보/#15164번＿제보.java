public class Main {
    static final int ISIZE = 1 << 21;
    static byte[] ibuf = new byte[ISIZE];
    static int iidx,isize;

    static byte read() throws Exception {
        if (iidx == isize) {
            isize = System.in.read(ibuf, iidx = 0, ISIZE);
        }
        return ibuf[iidx++];
    }

    static char[] nextStr() throws Exception {
        StringBuilder sb = new StringBuilder();
        byte c;
        while ((c = read()) != '\n' && c != -1) {
            sb.append((char)c);
        }
        return sb.toString().toCharArray();
    }

    static final int OSIZE = 1 << 20;
    static byte[] obuf = new byte[OSIZE];
    static int oidx = 0;

    static void write(long num) {
        if (num == 0) {
            obuf[oidx++] = '0';
            return;
        }

        int start = oidx;
        while (num > 0) {
            obuf[oidx++] = (byte)(num % 10 + '0');
            num /= 10;
        }
        int end = oidx - 1;
        while (start < end) {
            byte temp = obuf[start];
            obuf[start] = obuf[end];
            obuf[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) throws Exception {
        char[] s = nextStr();
        int n = s.length;
        long cnt = 0;
        int[] d1 = new int[n];
        int[] d2 = new int[n];

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : d1[l + r - i]<r - i + 1?d1[l + r - i]:r - i + 1;
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            cnt += d1[i];
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : d2[l + r - i + 1]<r - i + 1?d2[l + r - i + 1]:r - i + 1;
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k;
            cnt += d2[i];
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }

        write(cnt);
        System.out.write(obuf, 0, oidx);
    }
}
import java.io.IOException;

public class Main {
    private static final int BUFFER_SIZE = 1 << 20;
    private static byte[] buffer = new byte[BUFFER_SIZE];
    private static int bufferIdx = 0;
    private static int bytesRead = 0;

    static String read() throws IOException {
        StringBuilder sb = new StringBuilder();
        byte c;
        while ((c = readByte()) <= ' ');
        do {
            sb.append((char)c);
        } while ((c = readByte()) > ' ');
        return sb.toString();
    }

    private static byte readByte() throws IOException {
        if (bufferIdx == bytesRead) {
            bytesRead = System.in.read(buffer, 0, BUFFER_SIZE);
            bufferIdx = 0;
        }
        return buffer[bufferIdx++];
    }

    public static void main(String[] args) throws IOException {
        String S = read(),P=read();
        int[] f = new int[P.length()];
        int j = 0;
        for (int i = 1; i < P.length(); i++) {
            while (j > 0 && P.charAt(i) != P.charAt(j)) {
                j = f[j - 1];
            }
            f[i] = (P.charAt(i) == P.charAt(j)) ? ++j : 0;
        }
        j = 0;
        for (int i = 0; i < S.length(); i++) {
            while (j > 0 && S.charAt(i) != P.charAt(j)) {
                j = f[j - 1];
            }
            if (S.charAt(i) == P.charAt(j)) {
                if (++j == P.length()) {
                    System.out.print("1");
                    return;
                }
            }
        }
        System.out.print("0");
    }
}
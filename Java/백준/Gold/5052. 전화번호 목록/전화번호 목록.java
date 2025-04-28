import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
public class Main {
    private static final int BUFFER_SIZE = 1 << 16;
    private static final byte[] buffer = new byte[BUFFER_SIZE];
    private static int bufferIdx = 0;
    private static int bytesRead = 0;

    private static int readInt() throws Exception {
        int num = 0;
        byte c;
        while ((c = readByte()) <= ' ');
        do {
            num = num * 10 + (c - '0');
        } while ((c = readByte()) >= '0' && c <= '9');
        return num;
    }

    private static byte readByte() throws Exception {
        if (bufferIdx == bytesRead) {
            bytesRead = System.in.read(buffer, 0, BUFFER_SIZE);
            bufferIdx = 0;
        }
        return buffer[bufferIdx++];
    }

    private static String readLine() throws Exception {
        StringBuilder sb = new StringBuilder();
        byte c;
        while ((c = readByte()) != '\n' && c != '\r' && c != -1) {
            sb.append((char)c);
        }
        if (c == '\r') {
            readByte(); // consume '\n' in case of "\r\n"
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = readInt();
        while (T-- > 0) {
            int n = readInt();
            int[][] trie = new int[100000][10];
            boolean[] isEnd = new boolean[100000];
            int nodeCount = 1;
            boolean consistent = true;

            for (int i = 0; i < n; i++) {
                String s = readLine();
                if (!consistent) continue;

                int node = 0;
                for (int j = 0; j < s.length(); j++) {
                    int c = s.charAt(j) - '0';
                    if (trie[node][c] == 0) {
                        trie[node][c] = nodeCount++;
                    }
                    node = trie[node][c];
                    if (isEnd[node]) {
                        consistent = false;
                        break;
                    }
                }
                isEnd[node] = true;
                for (int c = 0; c < 10; c++) {
                    if (trie[node][c] != 0) {
                        consistent = false;
                        break;
                    }
                }
            }
            bw.write(consistent ? "YES\n" : "NO\n");
        }
        bw.flush();
    }
}
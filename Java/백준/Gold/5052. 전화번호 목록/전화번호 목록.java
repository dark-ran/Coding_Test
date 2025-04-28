import java.io.*;
import java.util.*;

public class Main {
    private static final int BUFFER_SIZE = 1 << 16;
    private static final byte[] buffer = new byte[BUFFER_SIZE];
    private static int bufferIdx = 0;
    private static int bytesRead = 0;

    private static int readInt() throws IOException {
        int num = 0;
        byte c;
        while ((c = readByte()) <= ' ');
        do {
            num = num * 10 + (c - '0');
        } while ((c = readByte()) >= '0' && c <= '9');
        return num;
    }

    private static byte readByte() throws IOException {
        if (bufferIdx == bytesRead) {
            bytesRead = System.in.read(buffer, 0, BUFFER_SIZE);
            bufferIdx = 0;
            if (bytesRead == -1) buffer[0] = -1;
        }
        return buffer[bufferIdx++];
    }

    private static String readLine() throws IOException {
        StringBuilder sb = new StringBuilder();
        byte c;
        while ((c = readByte()) != '\n' && c != -1) {
            sb.append((char)c);
        }
        return sb.toString();
    }

    private static final byte[] YES = "YES\n".getBytes();
    private static final byte[] NO = "NO\n".getBytes();
    private static final byte[] outputBuffer = new byte[200001];
    private static int ptr = 0;

    public static void main(String[] args) throws IOException {
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
                boolean createdNewNode = false;
                for (int j = 0; j < s.length(); j++) {
                    int c = s.charAt(j) - '0';
                    if (trie[node][c] == 0) {
                        trie[node][c] = nodeCount++;
                        createdNewNode = true;
                    }
                    node = trie[node][c];
                    if (isEnd[node]) {
                        consistent = false;
                        break;
                    }
                }
                isEnd[node] = true;
                if (!createdNewNode) {
                    consistent = false;
                }
            }
            if (consistent) {
                System.arraycopy(YES, 0, outputBuffer, ptr, 4);
                ptr += 4;
            } else {
                System.arraycopy(NO, 0, outputBuffer, ptr, 3);
                ptr += 3;
            }
        }
        System.out.write(outputBuffer, 0, ptr);
    }
}
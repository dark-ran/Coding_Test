public class Main {
    static int isize, iidx;
    static byte[] ibuf = new byte[1 << 21];

    static byte readByte() throws Exception {
        if (isize == iidx) {
            isize = System.in.read(ibuf, 0, 1 << 21);
            iidx = 0;
        }
        return ibuf[iidx++];
    }

    static int nextInt() throws Exception {
        int n = 0;
        byte c;
        while ((c = readByte()) < '0');
        do {
            n = (n << 3) + (n << 1) + (c & 15);
        } while ((c = readByte()) >= '0');
        return n;
    }

    static void nextStr(byte[] arr, int k) throws Exception {
        byte c;
        while ((c = readByte()) < 'A');
        arr[0] = c;
        for (int i = 1; i < k; i++) {
            arr[i] = readByte();
        }
    }

    public static void main(String[] args) throws Exception {
        int n = nextInt(), k = nextInt();
        byte[] arr = new byte[k];
        int sum = 0;
        Trie prie = new Trie();
        Trie suff = new Trie();

        for (int i = 0; i < n; i++) {
            nextStr(arr, k);
            sum += prie.insert(arr);
            nextStr(arr, k);
            int s=0,e=k-1;
            while(s<e){
                byte temp=arr[s];
                arr[s]=arr[e];
                arr[e]=temp;
                s++;
                e--;
            }
            sum += suff.insert(arr);
        }
        System.out.print(sum);
    }
}

class Trie {
    byte[] keys = new byte[4];
    Trie[] children = new Trie[4];
    int size = 0;

    int insert(byte[] arr) {
        Trie trie = this;
        int num = 0;
        for (byte c : arr) {
            int pos = -1;
            for (int i = 0; i < trie.size; i++) {
                if (trie.keys[i] == c) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                if (trie.size == trie.keys.length) {
                    byte[] newKeys = new byte[trie.size * 2];
                    Trie[] newChildren = new Trie[trie.size * 2];
                    System.arraycopy(trie.keys, 0, newKeys, 0, trie.size);
                    System.arraycopy(trie.children, 0, newChildren, 0, trie.size);
                    trie.keys = newKeys;
                    trie.children = newChildren;
                }
                trie.keys[trie.size] = c;
                trie.children[trie.size] = new Trie();
                pos = trie.size;
                trie.size++;
                num++;
            }
            trie = trie.children[pos];
        }
        return num;
    }
}
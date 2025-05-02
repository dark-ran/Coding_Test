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
            reverseArray(arr);
            sum += suff.insert(arr);
        }
        System.out.print(sum);
    }

    static void reverseArray(byte[] arr) {
        int s = 0, e = arr.length - 1;
        while (s < e) {
            byte temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
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
            int pos = binarySearch(trie, c);
            if (pos < 0) {
                pos = -(pos + 1);
                trie = ensureCapacity(trie, pos, c);
                num++;
            }
            trie = trie.children[pos];
        }
        return num;
    }

    private int binarySearch(Trie trie, byte c) {
        int left = 0, right = trie.size - 1;
        while (left <= right) {
            int mid = (left + right) >>> 1;
            byte midVal = trie.keys[mid];
            if (midVal < c) {
                left = mid + 1;
            } else if (midVal > c) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -(left + 1);
    }

    private Trie ensureCapacity(Trie trie, int pos, byte c) {
        if (trie.size == trie.keys.length) {
            byte[] newKeys = new byte[trie.size * 2];
            Trie[] newChildren = new Trie[trie.size * 2];
            System.arraycopy(trie.keys, 0, newKeys, 0, pos);
            System.arraycopy(trie.children, 0, newChildren, 0, pos);
            newKeys[pos] = c;
            newChildren[pos] = new Trie();
            System.arraycopy(trie.keys, pos, newKeys, pos + 1, trie.size - pos);
            System.arraycopy(trie.children, pos, newChildren, pos + 1, trie.size - pos);
            trie.keys = newKeys;
            trie.children = newChildren;
        } else {
            System.arraycopy(trie.keys, pos, trie.keys, pos + 1, trie.size - pos);
            System.arraycopy(trie.children, pos, trie.children, pos + 1, trie.size - pos);
            trie.keys[pos] = c;
            trie.children[pos] = new Trie();
        }
        trie.size++;
        return trie;
    }
}
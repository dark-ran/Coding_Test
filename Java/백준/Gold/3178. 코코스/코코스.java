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
        Trie pref = new Trie();
        Trie suff = new Trie();

        for (int i = 0; i < n; i++) {
            nextStr(arr, k);
            sum += pref.insert(arr);
            nextStr(arr, k);
            reverseArray(arr);
            sum += suff.insert(arr);
        }
        System.out.print(sum);
    }

    static void reverseArray(byte[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            byte temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

class Trie {
    byte[] keys = new byte[4];
    Trie[] children = null;
    int size = 0;

    final int insert(byte[] arr) {
        Trie current = this;
        int cnt = 0;
        for (byte c : arr) {
            int pos = current.BinarySearch(c);
            if (pos < 0) {
                pos = -(pos + 1);
                current = current.addChild(pos, c);
                cnt++;
            } else {
                current = current.children[pos];
            }
        }
        return cnt;
    }

    private int BinarySearch(byte c) {
        if (children == null) return -1;

        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) >>> 1;
            byte midVal = keys[mid];
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

    private Trie addChild(int pos, byte c) {
        if (children == null) {
            children = new Trie[4];
            keys[0] = c;
            children[0] = new Trie();
            size = 1;
            return children[0];
        }
        if (size == keys.length) {
            int newCapacity = size * 2;
            byte[] newKeys = new byte[newCapacity];
            Trie[] newChildren = new Trie[newCapacity];
            System.arraycopy(keys, 0, newKeys, 0, pos);
            System.arraycopy(children, 0, newChildren, 0, pos);
            newKeys[pos] = c;
            newChildren[pos] = new Trie();
            System.arraycopy(keys, pos, newKeys, pos + 1, size - pos);
            System.arraycopy(children, pos, newChildren, pos + 1, size - pos);
            keys = newKeys;
            children = newChildren;
        } else {
            System.arraycopy(keys, pos, keys, pos + 1, size - pos);
            System.arraycopy(children, pos, children, pos + 1, size - pos);

            keys[pos] = c;
            children[pos] = new Trie();
        }
        size++;
        return children[pos];
    }
}
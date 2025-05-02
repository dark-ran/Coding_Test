import java.util.HashMap;
public class Main{
    static int isize,iidx;
    static byte[]ibuf = new byte[1<<21];
    static byte readByte()throws Exception{
        if(isize==iidx){
            isize=System.in.read(ibuf,0,1<<21);
            iidx=0;
        }
        return ibuf[iidx++];
    }
    static int nextInt()throws Exception{
        int n = 0;
        byte c;
        while((c=readByte())<'0');
        do{
            n=(n<<3)+(n<<1)+(c&15);
        }while((c=readByte())>='0');
        return n;
    }
    static void nextStr(byte[]arr,int k)throws Exception{
        byte c;
        while((c=readByte())<'A');
        arr[0]=c;
        for(int i=1;i<k;i++){
            c=readByte();
            arr[i]=c;
        }
    }

    public static void main(String[] args)throws Exception {
        int n=nextInt(),k=nextInt();
        byte[]arr = new byte[k];
        int sum=0;
        Trie prie = new Trie();
        Trie suff = new Trie();
        for(int i=0;i<n;i++){
            nextStr(arr,k);
            sum += prie.insert(arr);
            nextStr(arr,k);
            int s=0,e=k-1;
            while(s<e){
                byte temp = arr[s];
                arr[s] = arr[e];
                arr[e] = temp;
                s++;
                e--;
            }
            sum += suff.insert(arr);
        }
        System.out.print(sum);
    }
}

class Trie{
    HashMap<Byte,Trie>child = new HashMap<>();
    int insert(byte[]arr){
        Trie trie = this;
        int num=0;
        for(int i=0;i<arr.length;i++) {
            if (!trie.child.containsKey(arr[i])) {
                trie.child.put(arr[i],new Trie());
                num++;
            }
            trie = trie.child.get(arr[i]);
        }
        return num;
    }
}
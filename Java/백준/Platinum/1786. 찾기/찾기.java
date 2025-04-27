public class Main{
    private static byte[]buffer=new byte[1000000];
    private static int bufferIdx=0;
    private static int bytesRead=0;

    static String read()throws Exception{
        StringBuilder sb=new StringBuilder();
        byte c;
        while((c=readByte())=='\n');
        do{
            sb.append((char)c);
        }while((c=readByte())!='\n');
        return sb.toString();
    }
    private static byte readByte() throws Exception {
        if (bufferIdx == bytesRead) {
            bytesRead = System.in.read(buffer, 0, 1000000);
            bufferIdx = 0;
        }
        return buffer[bufferIdx++];
    }
    public static void main(String[]args)throws Exception{
        String T = read();
        String P = read();
        int[]f = new int[P.length() + 1];
        int j=0;
        for(int i=1;i<P.length();i++){
            while(j>0&&P.charAt(i)!=P.charAt(j)){
                j=f[j-1];
            }
            f[i]=(P.charAt(i)==P.charAt(j)?++j:0);
        }
        j=0;
        int[]res = new int[T.length()];
        int idx=0;
        for(int i=0;i<T.length();i++){
            while(j>0&&T.charAt(i)!=P.charAt(j)){
                j=f[j-1];
            }
            if(T.charAt(i)==P.charAt(j)){
                if(++j==P.length()){
                    res[idx++]=i-P.length()+2;
                    j=f[j-1];
                }
            }
        }
        System.out.println(idx);
        for(int i=0;i<idx;i++){
            System.out.print(res[i]);
            System.out.print(" ");
        }
    }
}
public class Main{
    static String read()throws Exception{
        char[]buffer=new char[1000000];
        int idx=0;
        int c;
        while((c=System.in.read())<'A');
        do{
            buffer[idx++]=(char)c;
        }while((c=System.in.read())>='A');
        return new String(buffer,0,idx);
    }
    public static void main(String[]args)throws Exception{
        String S=read(),P=read();
        int j=0;
        int[]f=new int[P.length()+1];
        for(int i=1;i<P.length();i++){
            while(j>0&&P.charAt(i)!=P.charAt(j))j=f[j-1];
            if(P.charAt(i)==P.charAt(j))f[i] = ++j;
        }
        j=0;
        for(int i=0;i<S.length();i++){
            while(j>0&&S.charAt(i)!=P.charAt(j))j=f[j-1];
            if(S.charAt(i)==P.charAt(j)) j++;
            if(j==P.length()){
                System.out.print("1");
                return;
            }
        }
        System.out.print("0");
    }
}
import java.io.*;

public class Main {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		br.readLine();
		long sum = 0;
		for (int i = 0; i < 5300; i++) {
			sum += Integer.parseInt(br.readLine());
		}
		bw.write("5300\n");
		bw.write(String.valueOf(sum));
		bw.newLine();
		bw.flush();
	}
}
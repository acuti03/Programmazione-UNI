package es2;
import java.io.*;
import java.nio.charset.Charset;

public class FromInput extends Thread{

	private PipedOutputStream pos = null;


	public FromInput(PipedOutputStream pos){
		this.pos = pos;
	}
	
	public void run(){
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String line = null;

		try {
			while ((line = bf.readLine()) != null) {
				System.out.println("from stdin: " + line);
				byte[] bytes = line.getBytes(Charset.forName("UTF-8"));
				pos.write(bytes, 0, bytes.length);
				pos.flush();
			}
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}

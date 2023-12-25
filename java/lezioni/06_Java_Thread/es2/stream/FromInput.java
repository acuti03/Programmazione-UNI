package es2.stream;

import java.io.*;
import java.nio.charset.Charset;

public class FromInput extends Thread{
	
	private PipedOutputStream pos;

	public FromInput(PipedOutputStream pos){
		this.pos = pos;
	}

	public void run(){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		/*
		 * il thread deve continuare a leggere dallo standard input
		 * per scrivere l'output su pipeOutputStream
		 */
		String line = null;

		try {
			System.out.println("from - inserire uno o piu messaggi: ");

			while ((line = br.readLine()) != null) {
				System.out.println("From stdin: " + line);
				byte[] bytes = line.getBytes(Charset.forName("utf-8"));
				pos.write(bytes, 0, bytes.length);
				pos.flush();
			}
		} 
		catch (IOException e) {
			System.out.println(e);
		}
	}
}
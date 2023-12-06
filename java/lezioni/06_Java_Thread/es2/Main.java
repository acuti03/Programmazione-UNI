package es2;
import java.io.*;

public class Main {
	public static void main(String[] args){
		
		try {
			PipedOutputStream pos = new PipedOutputStream();
			PipedInputStream pis = new PipedInputStream(pos);

			FromInput input = new FromInput(pos);
			ToOutput output = new ToOutput(pis);

			input.start();
			output.start();

			pis.close();
			
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}

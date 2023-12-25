package es2.stream;

import java.io.*;
import java.nio.charset.Charset;
import java.util.*;

public class ToOutput extends Thread{

	private PipedInputStream pis;

	public ToOutput(PipedInputStream pis){
		this.pis = pis;
	}

	public void run(){
		try {
			byte[] buffer = new byte[1024];
			int nread = 0;

			while ((nread = pis.read(buffer)) > 0) {
				byte[] message_buffer = Arrays.copyOfRange(buffer, 0, nread);
				String message = new String(message_buffer, Charset.forName("UTF-8"));
				System.out.println(message);
			}
		} 
		catch (IOException e) {
			System.out.println(e);
		}
	}
}
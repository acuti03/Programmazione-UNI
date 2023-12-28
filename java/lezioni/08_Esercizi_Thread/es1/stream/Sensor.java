package stream;

import java.io.*;
import java.util.*;

public class Sensor extends Thread{
	
	private PipedOutputStream pos;

	public Sensor(PipedOutputStream pos){
		this.pos = pos;
	}

	@Override
	public void run(){

		final Random random = new Random();

		while (true) {
			String temp = "" + (18 + random.nextFloat() * (21 - 18));
			byte[] message = temp.getBytes();

			try { 
				pos.write(message);
				pos.flush();
				Thread.sleep(300);
			}
			catch (InterruptedException | IOException e) {
				e.printStackTrace();
			}
		}

	}


}

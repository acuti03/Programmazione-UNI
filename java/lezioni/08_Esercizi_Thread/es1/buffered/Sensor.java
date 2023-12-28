package buffered;

import java.io.*;
import java.util.Random;

public class Sensor extends Thread {
	
	private PipedOutputStream pos;

	public Sensor(PipedOutputStream pos){
		this.pos = pos;
	}

	@Override
	public void run(){

		final Random random = new Random();
		DataOutputStream dos = new DataOutputStream(pos);

		while (true) {
			try {
				float temp = 18 + random.nextFloat() * (21 - 18);
				dos.writeFloat(temp);
				dos.flush();
				Thread.sleep(300);
			}
			catch (InterruptedException | IOException e) {
				e.printStackTrace();
			}
		}
	}
}

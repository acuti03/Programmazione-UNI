package stream;

import java.io.*;
import java.nio.charset.Charset;

public class Actuator extends Thread {

	private PipedInputStream pis;
	private float tempDesiderata;

	public Actuator(PipedInputStream pis, float tempDesiderata){
		this.pis = pis;
		this.tempDesiderata = tempDesiderata;
	}

	@Override
	public void run(){

		byte[] buffer = new byte[128];

		try {
			while (pis.read(buffer) > 0) {
				String recived = new String(buffer, Charset.forName("UTF-8"));
				float temp = Float.parseFloat(recived);

				if(temp < tempDesiderata){
					System.out.println("*** ACCENDERE IL RISCALDAMENTO ***\n"
						+ "Temperatura corrente: " + temp + "\n"
						+ "Temperatura desiderata: " + tempDesiderata);
				}
				else{
					System.out.println("Temperatura corrente: " + temp);
				}
			}
		}
		catch (IOException e) {
			System.err.println("Errore nella lettura del sensore...");
			e.printStackTrace();
		}
	}
}

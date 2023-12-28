package buffered;

import java.io.*;

public class Actuator extends Thread{
	
	private PipedInputStream pis;
	private float tempDesiderata;

	public Actuator(PipedInputStream pis, float tempDesiderata){
		this.pis = pis;
		this.tempDesiderata = tempDesiderata;
	}

  	@Override
	public void run(){
		try {
			DataInputStream dis = new DataInputStream(pis);

			while (true) {
				float temp = dis.readFloat();

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
			e.printStackTrace();
		}
	}
}

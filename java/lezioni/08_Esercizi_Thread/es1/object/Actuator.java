package object;

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

		ObjectInputStream ois = null;
		float temp = 0;

		try {
			ois = new ObjectInputStream(pis);
			Message message = null;

			while (true) {
				if((message = (Message)ois.readObject()) == null) break;
				temp = message.getMessage();

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
		catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}

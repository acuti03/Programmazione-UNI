import java.io.*;

import object.Actuator;
import object.Sensor;

public class Main {
	public static void main(String[] args) {

		float temp = 0;
		PipedInputStream pis = new PipedInputStream();
		PipedOutputStream pos = null;
		Sensor sensor = null;
		Actuator actuator = null;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		System.out.println("Scrivi il valore della temperatura desiderata: ");
		
		try {
			temp = Float.parseFloat(br.readLine());
			pos = new PipedOutputStream(pis);
		}
		catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}

		sensor = new Sensor(pos);
		sensor.start();
		actuator = new Actuator(pis, temp);
		actuator.start();
	}
}

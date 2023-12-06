package es1;
import java.util.*;

public class Main {
	public static void main(String[] args) {

		Accomulatore a = new Accomulatore(0.0);
		int n;
		Scanner scanner = new Scanner(System.in);

		System.out.println("Inserisci il tuo N: ");
		n = Integer.parseInt(scanner.nextLine());

		scanner.close();
		CounterThread ct[] = new CounterThread[n];

		for(int i = 0; i < n; i++){
			ct[i] = new CounterThread(a);
			ct[i].start();
		}

		for(int i = 0; i < n; i++){
			try {
				ct[i].join();
			} catch (InterruptedException e) {
				System.out.println(e);
			}
		}

		System.out.println("Il valore di val è: " + a.getValue());
	}
}
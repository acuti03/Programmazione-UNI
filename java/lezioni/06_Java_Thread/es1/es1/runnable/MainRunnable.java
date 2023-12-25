package es1.runnable;

import es1.Accomulatore;

public class MainRunnable {

	final static int N = 25;
	public static void main(String[] args) {
		Accomulatore accomulatore = new Accomulatore(0.0);

		Thread[] threads = new Thread[N];

		for(int i = 0; i < N; i++){
			threads[i] = new Thread(new CounterThread(accomulatore));
			threads[i].start();
		}

		for(int i = 0; i < N; i++){
			try {
				threads[i].join();
			} 
			catch (InterruptedException e) {
				System.out.println(e);
			}
		}

		System.out.println("Thread: MAIN valore accomulatore: " + accomulatore.getValue());
	}
}
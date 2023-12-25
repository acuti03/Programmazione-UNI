package es1;

import java.io.*;
import es1.metodo2.WorkerThread;

public class Main {

	private static int checkRunningThreads(boolean[] array){
		int runningElements = 0;

		for(boolean e : array){
			if(e == true) runningElements++;
		}

		return runningElements;
	}

	public static void main(String[] args) {
		
		System.out.println(Thread.currentThread() + " init...");

		if(args.length != 1){
			System.err.println("Utilizzo Main <numeroThreads>");
			System.exit(-1);
		}
		
		int N = 0;

		try {
			N = Integer.parseInt(args[0]);
		}
		catch (NumberFormatException e) {
			System.err.println("Utilizzo Main <numeroThreads>");
			System.exit(-2);
		}

		WorkerThread[] wt = new WorkerThread[N];
		boolean[] running = new boolean[N];

		for(int i = 0; i < N; i++){
			wt[i] = new WorkerThread(i);
			Thread t = new Thread(wt[i]);
			t.start();
			running[i] = true;
		}

		while (checkRunningThreads(running) > 0) {
			System.out.println("Inserisci l'id del thread da terminare: ");
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

			try{
				int id = Integer.parseInt(br.readLine());

				if(id >= 0 && id < N){
					if(running[id] == true){
						wt[id].stop();
						running[id] = false;
					}
				}
			}
			catch(IOException e){
				e.printStackTrace();
			}
			catch(NumberFormatException e){
				System.err.println("Errore, non è un numero intero!");
			}
		}
	}
}

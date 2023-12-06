package es1;
import java.util.*;

public class CounterThread extends Thread{

	private Accomulatore acc;
	

	public CounterThread(Accomulatore a){
		this.acc = a;
	}

	public void run(){
		Random rand = new Random();
		acc.addValue(rand.nextInt(10));
		System.out.println("Thread: " + Thread.currentThread() + "accomulatore: " + acc.getValue());
	}

}
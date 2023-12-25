package es1.runnable;

import es1.Accomulatore;

public class CounterThread implements Runnable{

    private Accomulatore accomulatore;

    public CounterThread(Accomulatore accomulatore){
        this.accomulatore = accomulatore;
    }

    public void run() {
        double val = Math.random();
        accomulatore.addValue(val);
        System.out.println("Thread: " + Thread.currentThread() + " accomulatore: " + accomulatore.getValue());
    }

    
}

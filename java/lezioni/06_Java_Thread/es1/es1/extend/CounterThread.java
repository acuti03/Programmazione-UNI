package es1.extend;

import es1.Accomulatore;

public class CounterThread extends Thread{
    
    private Accomulatore accomulatore;

    public CounterThread(Accomulatore accomulatore){
        this.accomulatore = accomulatore;
    }

    public void run(){
        double value = Math.random();
        accomulatore.addValue(value);
        System.out.println("Thread: " + Thread.currentThread() + " accomulatore: " + accomulatore.getValue());
    }
}

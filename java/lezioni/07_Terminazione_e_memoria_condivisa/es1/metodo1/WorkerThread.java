package es1.metodo1;

import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThread implements Runnable {

    private int id;
    private final AtomicBoolean running = new AtomicBoolean(false);

    public WorkerThread(int id){
        this.id = id;
    }

    public void stop(){
        running.set(false);
    }

    @Override
    public void run(){
        running.set(true);
        
        while (running.get()) {
            //System.out.println(Thread.currentThread());

            try{
                System.out.println("Thread " + id + " è ancora in corso");
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                Thread.currentThread().interrupt();
                e.printStackTrace();
            }
        }
    }
}
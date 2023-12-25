package es1.metodo2;

import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThread implements Runnable{
    
    private int id;
    private final AtomicBoolean running;

    public WorkerThread(int id){
        this.id = id;
        running = new AtomicBoolean(false);
    }

    public void stop(){
        running.set(false);
        Thread.currentThread().interrupt();
    }

    @Override
    public void run(){
        running.set(true);

        while (running.get()) {

            try{
                System.out.println("Thread: " + id);
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                Thread.currentThread().interrupt();
                System.out.println(Thread.currentThread() + " è stato interrotto");
            }
        }
    }
    
}

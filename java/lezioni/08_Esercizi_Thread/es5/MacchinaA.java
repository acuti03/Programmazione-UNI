package es3;

import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable{

    private AtomicBoolean isRunning;
    private ControlloProduzione controlloProduzione;

    public MacchinaA(ControlloProduzione controlloProduzione){
        this.controlloProduzione = controlloProduzione;
        isRunning = new AtomicBoolean(false);
    }

    @Override
    public void run() {
        isRunning.set(true);

        while (isRunning.get()) {
            
            System.out.println("Inizio lavorazione semilavorato");

            try {
                int sleepTime = 400 + (int)(Math.random() * 100);
                Thread.sleep(sleepTime);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Fine lavorazione semilavorato");
            controlloProduzione.incrementaSemilavorati();
        }
    }
    
    public void stop() {
        isRunning.set(false);
    }
}

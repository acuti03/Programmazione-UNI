package es4;

import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaProduzione extends Thread{

    private AtomicBoolean isRunning;
    private Macchina macchina;

    public SimulaProduzione(Macchina macchina){
        this.macchina = macchina;
        this.isRunning = new AtomicBoolean(false);
    }
    
    public void run(){
        isRunning.set(false);
        int pezziProdotti = 0;

        while(isRunning.get()){
            pezziProdotti += (int)(Math.random() * 100);
            macchina.setPezziProdotti(pezziProdotti);

            try {
                Thread.sleep(2000);
            }
            catch(InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopThread(){
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}

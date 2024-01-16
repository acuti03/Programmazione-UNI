package es3;

import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {
    
    private AtomicBoolean isRunning;
    private PipedOutputStream pos;
    private ControlloProduzione controlloProduzione;
    private int lavoratiFiniti;

    public MacchinaB(PipedOutputStream pos, ControlloProduzione controlloProduzione){
        this.pos = pos;
        this.controlloProduzione = controlloProduzione;
        this.isRunning = new AtomicBoolean(false);
        this.lavoratiFiniti = 0;
    }

    @Override
    public void run(){
        isRunning.set(true);

        while(isRunning.get()) {
            
            int semilavoratiDis = controlloProduzione.getSemilavorati();

            if(semilavoratiDis > 0){
                controlloProduzione.decrementaSemilavorati();
            }
            else{
                System.out.println("MacchinaB: semilavorati insufficienti per avviare la produzione");

                try {
                    Thread.sleep(2000);
                } 
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            try {
                Thread.sleep(100 + (int)(Math.random() * 50));
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            lavoratiFiniti++;
            controlloProduzione.incrementaProdottiFiniti();
            System.out.println("Fine lavorazione prodotto, lavori finiti: " + lavoratiFiniti);

            String message = "prodotto-finito";

            try {
                pos.write(message.getBytes("UTF-8"));
                pos.flush();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    public void stop(){
        isRunning.set(false);
    }
}

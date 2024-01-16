package es1;

import java.util.*;

public class Macchina extends Thread{

    private Produzione produzione;

    public Macchina(Produzione produzione){
        this.produzione = produzione;
    }

    @Override
    public void run(){
        Random random = new Random();

        for(int i = 0; i < 35; i++){

            System.out.println(Thread.currentThread() + "siamo in produzione...");

            long sleepTime = 500 + (long)(random.nextDouble() * 100);

            try {
                Thread.sleep(sleepTime);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
            produzione.incrementa();
        }
    }
}

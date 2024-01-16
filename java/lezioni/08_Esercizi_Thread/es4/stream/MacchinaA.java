package es2.stream;

import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable{

    private PipedOutputStream pos;
    private final AtomicBoolean isRunning;

    public MacchinaA(PipedOutputStream pos){
        this.pos = pos;
        this.isRunning = new AtomicBoolean(false);
    }

    @Override
    public void run(){
        isRunning.set(true);


        while(isRunning.get()){
            System.out.println("Lavorazione prodotto in corso...");

            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Fine lavorazione prodotto");

            String pg = "Prodotto-grezzo";
            byte message[] = null;

            try {
                message = pg.getBytes("UTF-8");
                pos.write(message);
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

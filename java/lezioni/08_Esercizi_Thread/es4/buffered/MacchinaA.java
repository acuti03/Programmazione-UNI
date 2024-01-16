package es2.buffered;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable{
    
    private PipedOutputStream pos;
    private AtomicBoolean isRunning;

    public MacchinaA(PipedOutputStream pos){
        this.pos = pos;
        this.isRunning = new AtomicBoolean(false);
    }

    @Override
    public void run(){
        isRunning.set(true);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while(isRunning.get()) {
            System.out.println("Lavorazione prodotto in corso...");

            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Fine lavorazione prodotto");

            String pg = "Prodotto grezzo";

            try {
                bw.write(pg);
                bw.newLine();
                bw.flush();
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
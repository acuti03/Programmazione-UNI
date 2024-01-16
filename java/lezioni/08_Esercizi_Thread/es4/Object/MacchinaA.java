package es2.Object;

import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    
    private PipedOutputStream pos;
    private AtomicBoolean isRunning;

    public MacchinaA(PipedOutputStream pos){
        this.pos = pos;
        isRunning = new AtomicBoolean(false);
    }

    @Override
    public void run(){
        isRunning.set(true);
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        while(isRunning.get()) {
            System.out.println("Inizio lavorazione del prodotto...");
            Message message;

            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            message = new Message("prodotto grezzo");

            try {
                oos.writeObject(message);
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

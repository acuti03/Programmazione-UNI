package es2.Object;

import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {
    
    private PipedInputStream pis;
    private AtomicBoolean isRunning;
    private int lavoriFiniti;

    public MacchinaB(PipedInputStream pis){
        this.pis = pis;
        isRunning = new AtomicBoolean(false);
        lavoriFiniti = 0;
    }

    @Override
    public void run(){
        isRunning.set(true);
        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        while(isRunning.get()) {
            Message message = null;

            try {
                message = (Message)ois.readObject();
            }
            catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }

            System.out.println("Prodotto grezzo arrivato: " + message.getMessage());

            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            lavoriFiniti++;
            System.out.println("Prodotto grezzo lavorato. Prodotti finiti: " + lavoriFiniti);
        }
    }

    public void stop(){
        isRunning.set(false);
    }
}

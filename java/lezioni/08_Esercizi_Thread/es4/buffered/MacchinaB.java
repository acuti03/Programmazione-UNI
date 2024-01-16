package es2.buffered;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable{
    
    private AtomicBoolean isRunning;
    private PipedInputStream pis;
    private int lavoriFiniti;

    public MacchinaB(PipedInputStream pis){
        this.pis = pis;
        isRunning = new AtomicBoolean(false);
        lavoriFiniti = 0;
    }

    @Override
    public void run() {
        isRunning.set(true);
        BufferedReader br = new BufferedReader(new InputStreamReader(pis));

        while(isRunning.get()) {
            String message = null;

            try {
                message = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println("Arrivato pezzo grezzo: " + message);

            try {
                Thread.sleep(200);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }

            lavoriFiniti++;

            System.out.println("Lavorazione pezzo grezzo terminata, lavori finiti: " + lavoriFiniti);
        }
    }

    public void stop() {
        isRunning.set(false);
    }
}
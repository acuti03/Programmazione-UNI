package es2.stream;

import java.io.*;
import java.nio.charset.Charset;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable{

    private PipedInputStream pis;
    private final AtomicBoolean isRunning;
    private int lavoriFiniti;


    public MacchinaB(PipedInputStream pis){
        this.pis = pis;
        this.isRunning = new AtomicBoolean(false);
        this.lavoriFiniti = 0;
    }

    @Override
    public void run(){
        isRunning.set(true);

        while(isRunning.get()) {
            
            byte buffer[] = new byte[128];

            try{
                pis.read(buffer);
            }
            catch(IOException e){
                e.printStackTrace();
            }

            String revived = new String(buffer, Charset.forName("UTF-8"));
            System.out.println("Arrivato prodotto grezzo: " + revived);

            try{
                Thread.sleep(200);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
            lavoriFiniti++;
            System.out.println("Prodotto grezzo finito, lavori finiti: " + lavoriFiniti);
        }

    }

    public void stop(){
        isRunning.set(false);
    }
    
}
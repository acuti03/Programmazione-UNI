package prova;

import java.util.concurrent.atomic.AtomicBoolean;
import java.io.*;
import java.util.*;

public class RilevatoreAria extends Thread{
    
    private AtomicBoolean isRunning;
    private PipedOutputStream pos;

    public RilevatoreAria(PipedOutputStream pos){
        isRunning = new AtomicBoolean(false);
        this.pos = pos;
    }

    @Override
    public void run(){
        isRunning.set(true);
        Random random = new Random();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
        String time = null;
        String pollini = null;

        while (isRunning.get()) {
            pollini = Integer.toString(random.nextInt(111));
            time = Double.toString(System.currentTimeMillis() / 1000.0);

            try {
                bw.write(pollini);
                bw.newLine();
                bw.write(time);
                bw.newLine();
                bw.flush();
            }
            catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(12000);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void fermaRilevatoreAria(){
        isRunning.set(false);
    }
}
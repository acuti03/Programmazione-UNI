package es2.buffer;

import java.io.*;

public class ToOutput extends Thread{
    
    private PipedInputStream pis;

    public ToOutput(PipedInputStream pis){
        this.pis = pis;
    }

    public void run(){
        System.out.println(Thread.currentThread() + " ToOutput");

        try {
            String line = null;
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));

            while ((line = br.readLine()) != null) {
                System.out.println("ToOutput " + line);
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }
}

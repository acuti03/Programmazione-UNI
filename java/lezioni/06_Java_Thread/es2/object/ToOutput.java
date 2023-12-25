package es2.object;

import java.io.*;

public class ToOutput extends Thread{
    
    private PipedInputStream pis;

    public ToOutput(PipedInputStream pis){
        this.pis = pis;
    }

    public void run(){
        System.out.println(Thread.currentThread() + " ToOutput");
        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);

            while(true) {
                Message message = (Message)ois.readObject();

                if(message == null) break;

                System.out.println("ToOutput: " + message.getMess());
            }
        }
        catch (IOException | ClassNotFoundException e) {
            System.out.println(e);
        }
    }
}

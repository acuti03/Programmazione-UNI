package es2.object;

import java.io.*;

public class FromInput extends Thread{
    
    private PipedOutputStream pos;

    public FromInput(PipedOutputStream pos){
        this.pos = pos;
    }

    public void run(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
            System.out.println("FromInput - Inserire uno o piu messaggi: ");

            while ((line = br.readLine()) != null) {
                Message message = new Message(line);
                oos.writeObject(message);
                oos.flush();
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }
}

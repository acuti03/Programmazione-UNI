package object;

import java.io.*;
import java.util.*;

public class Sensor extends Thread{
    
    private PipedOutputStream pos;

    public Sensor(PipedOutputStream pos){
        this.pos = pos;
    }

    @Override
    public void run(){

        final Random random = new Random();
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        while (true) {
            try {
                float temp = 18 + random.nextFloat() * (21 - 18);
                Message message = new Message(temp);

                oos.writeObject(message);
                oos.flush();
                
                Thread.sleep(300);
            }
            catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

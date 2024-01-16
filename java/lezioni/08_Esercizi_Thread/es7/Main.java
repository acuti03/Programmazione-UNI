package prova;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;
        BufferedReader br = null;
        RilevatoreAria rilevatoreAria = null;
        int pollini = 0;
        double newTime = 0, time = 0, diff = 0;

        try {
            pos = new PipedOutputStream(pis);
            br = new BufferedReader(new InputStreamReader(pis));
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        rilevatoreAria = new RilevatoreAria(pos);
        rilevatoreAria.start();

        for(int i = 0; i < 8; i++){
            try {
                pollini = Integer.parseInt(br.readLine());
                newTime = Double.parseDouble(br.readLine());
            }
            catch (NumberFormatException e) {
                e.printStackTrace();
            }
            catch (IOException e) {
                e.printStackTrace();
            }

            if(pollini < 20){
                System.out.println("Basso " + pollini);
            }
            else if(pollini <= 75){
                System.out.println("Medio " + pollini);
            }
            else{
                System.out.println("Alto " + pollini);
            }

            diff = newTime - time;
            
            if(newTime > diff && time != 0){
                System.out.println("Attenzione " + newTime);
            }
            System.out.println(newTime);

            time = newTime;
        }

        rilevatoreAria.fermaRilevatoreAria();

        try {
            rilevatoreAria.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
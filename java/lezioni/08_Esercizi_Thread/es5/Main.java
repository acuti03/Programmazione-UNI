package es3;

import java.io.*;
import java.nio.charset.Charset;

public class Main {
    public static void main(String[] args) {
        
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
        }

        ControlloProduzione controlloProduzione = new ControlloProduzione();

        MacchinaA mA1 = new MacchinaA(controlloProduzione);
        MacchinaA mA2 = new MacchinaA(controlloProduzione);
        Thread tmA1 = new Thread(mA1);
        Thread tmA2 = new Thread(mA2);

        tmA1.start();
        tmA2.start();

        MacchinaB mB = new MacchinaB(pos, controlloProduzione);
        Thread tmB = new Thread(mB);

        tmB.start();

        for(int i = 0; i < 15; i++){
            byte buffer[] = new byte[128];

            try {
                pis.read(buffer);
            }
            catch (IOException e) {
                e.printStackTrace();
            }

            String message = new String(buffer, Charset.forName("UTF-8"));
            System.out.println("Main - Arrivato prodotto finito - " + message);
        }

        mA1.stop();
        mA2.stop();
        mB.stop();

        try {
            tmA1.join();
            tmA2.join();
            tmB.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Prodotti semilavorati: " + controlloProduzione.getSemilavorati() + 
        " Prodotti finiti: " + controlloProduzione.getProdottiFiniti());
    }
}

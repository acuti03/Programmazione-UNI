package es4;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int obbiettivoProduzione = 0, id = 0;
        Macchina macchina = new Macchina();
        
        System.out.println("Inserire l'id della macchina da monitorare: ");
        try {
            id = Integer.parseInt(br.readLine());
        }
        catch (NumberFormatException | IOException e) {
            e.printStackTrace();
        }

        System.out.println("Inserire l'obbiettivo: ");
        try {
            obbiettivoProduzione = Integer.parseInt(br.readLine());
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        macchina.setMacchinaID(id);
        macchina.setPezziProdotti(0);

        SimulaProduzione simulaProduzione = new SimulaProduzione(macchina);

        simulaProduzione.start();

        for(int i = 0; i < 10; i++){

            try {
                Thread.sleep(10000);
                System.out.println("Pezzi totali prodotti: " + macchina.getPrezziProdotti() +
                "Dalla macchina: " + macchina.getMacchinaID());
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        if(macchina.getPrezziProdotti() > obbiettivoProduzione){
            System.out.println("Obbiettivo raggiunto");
        }

        simulaProduzione.stopThread();

        try {
            simulaProduzione.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

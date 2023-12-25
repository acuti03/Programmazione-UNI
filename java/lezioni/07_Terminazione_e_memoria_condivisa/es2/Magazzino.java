package es2;

import java.util.*;

public class Magazzino {

    private Map<String, Integer> oggetti = null;

    public Magazzino(){
        oggetti = new HashMap<String, Integer>();
    }

    public synchronized boolean verificaOggetto(String oggetto){

        try {
            Thread.sleep(500);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        return oggetti.containsKey(oggetto);
    }

    public void aggiungiOggetto(String oggetto){

        try {
            Thread.sleep(500);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        if(!verificaOggetto(oggetto)){
            oggetti.put(oggetto, 0);
        }
        else{
            System.err.println("L'oggetto esiste gia in magazzino");
        }
    }

    public synchronized void aggiungiQuantita(String oggetto, int quantita){

        try {
            Thread.sleep(500);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }

        if(!(quantita + oggetti.get(oggetto) >= 0)){
            System.err.println("La quantita deve essere >= 0");
            return;
        }

        if(!verificaOggetto(oggetto)){
            System.err.println("L'oggetto non esiste in magazzino");
            return;
        }

        oggetti.put(oggetto, oggetti.get(oggetto) + quantita);
    }

    public synchronized String toString() {
        String result = "";

        for(Map.Entry<String, Integer> obj : oggetti.entrySet()){
            result += "- " + obj.getKey() + ": " + obj.getValue() + "\n";
        }

        return result;
    }


}

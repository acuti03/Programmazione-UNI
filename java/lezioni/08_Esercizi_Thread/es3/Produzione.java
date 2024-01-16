package es1;


public class Produzione {

    private int prodotti;

    public Produzione(){
        this.prodotti = 0;
    }
    
    public synchronized void incrementa(){
        int temp = prodotti;
        Simulate.HWinterrupt();
        temp++;
        prodotti = temp;
    }

    public synchronized String stampaProduzione(){
        return "Valore produzione: " + prodotti;
    }
}

package es4;

public class Macchina {

    private int id, pezziProdotti;
    
    public synchronized void setMacchinaID(int id){
        this.id = id;
    }

    public synchronized int getMacchinaID(){
        return id;
    }

    public synchronized void setPezziProdotti(int pezzi){
        this.pezziProdotti = pezzi;
    }

    public synchronized int getPrezziProdotti(){
        return pezziProdotti;
    }
}

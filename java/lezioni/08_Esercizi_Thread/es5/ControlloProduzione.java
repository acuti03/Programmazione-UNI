package es3;

public class ControlloProduzione {
    
    private int semilavorati, prodottiFiniti;

    public ControlloProduzione(){
        this.semilavorati = 0;
        this.prodottiFiniti = 0;
    }

    public synchronized void incrementaSemilavorati(){
        int temp = semilavorati;
        temp++;
        semilavorati = temp;
    }

    public synchronized void decrementaSemilavorati(){
        int temp = semilavorati;
        temp--;
        semilavorati = temp;
    }

    public synchronized void incrementaProdottiFiniti(){
        int temp = prodottiFiniti;
        temp++;
        prodottiFiniti = temp;
    }

    public int getSemilavorati(){
        return semilavorati;
    }

    public int getProdottiFiniti(){
        return prodottiFiniti;
    }
}

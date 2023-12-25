package es2;

public class Operatore extends Thread{
    
    private Magazzino magazzino;

    public Operatore(Magazzino magazzino){
        this.magazzino = magazzino;
    }

    @Override
    public void run(){

        if(!magazzino.verificaOggetto("bulloni")){
            System.out.println(Thread.currentThread().getId() + " In magazzio non esiste bulloni quindi lo creo");
            magazzino.aggiungiOggetto("bulloni");

            Simulate.Break();
        }
        
        System.out.println(Thread.currentThread().getId() + " Aggiungo 1000 bulloni");
        magazzino.aggiungiQuantita("bulloni", 1000);

        Simulate.Break();

        System.out.println(Thread.currentThread().getId() + " Tolgo 1000 bulloni");
        magazzino.aggiungiQuantita("bulloni", -1000);
    }
}

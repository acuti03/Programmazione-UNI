package es1;

public class Main{
    public static void main(String[] args) {
        
        final int N = 10;

        Macchina macchine[] = new Macchina[N];
        Produzione produzione = new Produzione();

        for(int i = 0; i < N; i++){
            macchine[i] = new Macchina(produzione);
            macchine[i].start();
        }

        for(int i = 0; i < N; i++){
            try {
                macchine[i].join();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Produzione corretta: " + (N * 35));
        System.out.println("Produzione effettuata: " + produzione.stampaProduzione());
    }
}
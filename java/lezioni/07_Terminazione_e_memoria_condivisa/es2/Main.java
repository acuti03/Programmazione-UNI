package es2;

public class Main {
    
    final static int N = 5;
    public static void main(String[] args) {

        Magazzino magazzino = new Magazzino();
        Operatore[] operatori = new Operatore[N];

        for(int i = 0; i < N; i++){
            operatori[i] = new Operatore(magazzino);
            operatori[i].start();
        }
        
        for(int i = 0; i < N; i++){
            try {
                operatori[i].join();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Magazzino:\n" + magazzino);

    }
}

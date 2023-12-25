package es2;

public class Simulate {

    public static void Break() {

        if(Math.random() < 0.5){

            try {
                Thread.sleep(500);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

package es1;


public class Simulate {
    public static void HWinterrupt(){
        if(Math.random() <= 0.25){
            try{
                Thread.sleep(200);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}

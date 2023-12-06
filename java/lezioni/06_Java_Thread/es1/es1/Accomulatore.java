package es1;

public class Accomulatore {
    private double val;

    public Accomulatore(double val){
        this.val = val;
    }

    public void addValue(double val){
        this.val += val;

        try{
            Thread.sleep(200);
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }

    public double getValue(){
        return val;
    }
}

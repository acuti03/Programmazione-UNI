public class DrawableRetangle extends Retangle implements Drawable{
    protected int c;
    protected double x, y;

    public DrawableRetangle(double w, double h){
        super(w, h);
    }

    public void setColor(int c){
        this.c = c;
    }

    public void setPosition(double x, double y){
        this.x = x;
        this.y = y;
    }

    public void draw(){
        System.out.println("Rettangolo in posizione x: " + x + " y: " + y + " di colore: " + c);
    }
}

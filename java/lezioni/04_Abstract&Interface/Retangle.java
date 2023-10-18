public class Retangle extends Shape{
    protected double w;
    protected double h;

    public Retangle(double w, double h){
        this.w = w;
        this.h = h;
    }

    public double area(){
        return w * h;
    }

    public double perimetro(){
        return 2 * (w + h);
    }

    public double getWidth(){
        return w;
    }

    public double getHeight(){
        return h;
    }

    public void whoami(){
        System.out.println("Ciao sono un rettangolo");
    }
}

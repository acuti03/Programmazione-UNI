public class Circle extends Shape{
    protected double r;

    public Circle(double r){
        this.r = r;
    }

    public double area(){
        return Math.PI * r * r;
    }

    public double perimetro(){
        return 2 * Math.PI * r;
    }

    public void whoami(){
        System.out.println("Ciao sono un cerchio");
    }
}

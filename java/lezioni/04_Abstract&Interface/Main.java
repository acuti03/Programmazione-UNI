public class Main{
	public static void main(String[] args) {
/*      Shape[] shapes = new Shape[10];
		
		for (Shape shape : shapes) {
			int n = (int)(1 + Math.random() * 2);

			switch(n){
				case 1:
					shape = new Circle(1.0);
					break;
				case 2:
					shape = new Retangle(1.0, 1.5);
					break;
				default:
					System.out.println("Errore");
			}

			shape.whoami();
		} */

		Drawable[] drawables = new Drawable[10];

		for (Drawable draw : drawables) {
			int n = (int)(1 + Math.random() * 2);

			switch(n){
				case 1:
					draw = new DrawableCircle(1.0);
					draw.setPosition(Math.random(), Math.random());
					draw.setColor((int)Math.random());
					break;
				case 2:
					draw = new DrawableRetangle(5.1,1.2);
					draw.setPosition(Math.random(), Math.random());
					draw.setColor((int)Math.random());
					break;
				default:
					System.out.println("Errore");
			}
		}
	}
}
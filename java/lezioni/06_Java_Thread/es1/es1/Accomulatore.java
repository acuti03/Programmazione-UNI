package es1;

public class Accomulatore {
	private double accomulatore;

	public Accomulatore(double val){
		accomulatore = val;
	}

	public void addValue(double val){

		try {
			Thread.sleep(200);
		} 
		catch(InterruptedException e){
			System.out.println(e);
		}

		accomulatore += val;
	}

	public double getValue(){
		return accomulatore;
	}
}
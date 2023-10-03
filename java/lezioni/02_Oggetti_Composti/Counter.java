public class Counter{
	private int val;

	public Counter(){
		val = 1;
	}

	public Counter(int n){
		val = n;
	}

	public void inc(){
		val++;
	}

	public void reset(){
		val = 0;
	}

	public int getValue(){
		return val;
	}
}
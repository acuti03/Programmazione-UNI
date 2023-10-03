public class Main {
	public static void main(String[] args) {
		CounterDec cd = new CounterDec(0);

		cd.reset();
		cd.inc();
		cd.inc();
		System.out.println(cd.getValue());
		cd.dec();
		System.out.println(cd.getValue());
	}
}
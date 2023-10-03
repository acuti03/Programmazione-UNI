class Main{
	public static void main(String[] args){
		Counter cont1 = new Counter(1);
		Counter cont2 = new Counter(0);
		Counter cont3 = new Counter(0.5F);
		boolean b1;

		cont1.inc();
		cont2.inc();
		//cont2.copy(cont1);
		b1 = cont1.equals(cont2);
		System.out.println(b1);
		cont3.print();

		cont2.print();
	}
}
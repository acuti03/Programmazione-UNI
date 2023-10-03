class Counter{
	double i;

	Counter(int i){
		this.i = i; 
	}
	Counter(double i){
		this.i = i;
	}

	void reset(){
		i = 0;
	}
	void inc(){
		i++;
	}
	void inc(int n){
		i += n;
	}
	void dec(){
		i--;
	}
	void print(){
		System.out.println(i);
	}
	void copy(Counter c){
		i = c.i;
	}
	boolean equals(Counter c){
		return i == c.i;
	}
}
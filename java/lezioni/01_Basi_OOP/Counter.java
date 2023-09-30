class Counter{
    int i;

    Counter(int i){
       this.i = i; 
    }

    void reset(){
        i = 0;
    }
    void incrementa(){
        i++;
    }
    void decrementa(){
        i--;
    }
    void stampa(){
        System.out.println(i);
    }
    void copy(Counter c){
        i = c.i;
    }
}
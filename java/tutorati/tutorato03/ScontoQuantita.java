public class ScontoQuantita extends PoliticaSconto{
    protected double minimo;
    protected double percentuale;

    public ScontoQuantita(double minimo, double percentuale){
        this.minimo = minimo;
        this.percentuale = percentuale;
    }

    public double calcolaSconto(int numeroArticoli, double prezzoArticolo){
        if(numeroArticoli > minimo){
            
        }

        return percentuale;
    }
}

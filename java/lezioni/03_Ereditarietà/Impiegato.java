public class Impiegato extends Persona{
    private int matricola;

    public Impiegato(String nome, String cognome, int eta, int matricola){
        super(nome, cognome, eta);
        this.matricola = matricola;
    }

    public void stampa(){
        System.out.println("Nome: " + nome + " Cognome: " + cognome + " Eta: " + eta + " Matricola: " + matricola);
    }
}

public class Impiegato extends Persona{
    private String azienda;
    private int matricola;

    public Impiegato(String nome, String cognome, int eta, String azienda, int matricola){
        super(nome, cognome, eta);
        this.azienda = azienda;
        this.matricola = matricola;
    }

    public void stampa(){
        System.out.println("Nome: " + nome + " Cognome: " + cognome + " Eta: " + eta + " Azienda: " + azienda + " Matricola: " + matricola);
    }
}

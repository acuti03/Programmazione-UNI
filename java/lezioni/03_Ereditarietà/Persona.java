public class Persona {
    protected String nome;
    protected String cognome;
    protected int eta;

    public Persona(String nome, String cognome, int eta){
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
    }

    public void stampa(){
        System.out.println("Nome: " +  nome + " Cognome: " + cognome + " eta: " + eta);
    }

}

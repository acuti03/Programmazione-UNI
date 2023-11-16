public class Main {
    public static void main(String[] args) {
        Persona persona = new Persona("simone", "acuti", 19);
        Impiegato impiegato = new Impiegato("alessio", "ganzarolli", 20, "siridea", 2203);
        
        persona.stampa();
        impiegato.stampa();
    }
}
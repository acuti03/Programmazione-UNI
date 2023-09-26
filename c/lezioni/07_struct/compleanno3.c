#include <stdio.h>

typedef enum{
    Gennaio,
    Febbraio,
    Marzo,
    Aprile,
    Maggio,
    Giugno,
    Luglio,
    Agosto,
    Settembre,
    Ottobre,
    Novembre,
    Dicembre
} Mesi;

typedef struct{
    int giorno;
    Mesi mese;
    int anno;
} Data;


typedef struct{
    char nome[25];
    Data dataNascita;

} Persona;



int main(){
    Data oggi;
    Persona persona;

    printf("Digita la data di oggi: \n");
    scanf("%d%d%d", &oggi.giorno, &oggi.mese, &oggi.anno);

    printf("\nDigita il tuo nome e la tua data di nascita:\n");
    scanf("%s%d%d%d", persona.nome, &persona.dataNascita.giorno, &persona.dataNascita.mese, &persona.dataNascita.anno);

    if(persona.dataNascita.giorno == oggi.giorno && persona.dataNascita.mese == oggi.mese){
        printf("\nAuguri! %s", persona.nome);
    }

    printf("\n");
    return 0;
}
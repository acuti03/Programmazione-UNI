#include <stdio.h>


typedef struct{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct{
    char nome[25];
    Data dataNascita;
} Persona;



int main(){
    Persona simone;
    Data oggi;

    printf("\nInserire la data di oggi:\n");
    scanf("%d%d%d", &oggi.giorno, &oggi.mese, &oggi.anno);

    printf("\nInserire il nome e la data di compleanno:\n");
    scanf("%s%d%d%d", simone.nome, &simone.dataNascita.giorno, &simone.dataNascita.mese, &simone.dataNascita.anno);

    if(oggi.giorno == simone.dataNascita.giorno && oggi.mese == simone.dataNascita.mese){
        printf("\nAuguri! %s",simone.nome);
    }



    printf("\n");
    return 0;
}
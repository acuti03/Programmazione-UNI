#include <stdio.h>

struct data{
    int giorno;
    int mese;
    int anno;
} d1;

struct persona{
    char nome[25];
    struct data dataNascita;
} p1;



int main(){
    
    printf("\nInserisci la data di oggi:\n");
    scanf("%d%d%d", &d1.giorno, &d1.mese, &d1.anno);

    printf("\nInserisci il tuo nome e data di nascita:\n");
    scanf("%s%d%d%d", p1.nome, &p1.dataNascita.giorno, &p1.dataNascita.mese, &p1.dataNascita.anno);

    if(d1.giorno == p1.dataNascita.giorno && d1.mese == p1.dataNascita.mese){
        printf("\nAuguri! %s", p1.nome);
    }

    printf("\n");
    return 0;
}
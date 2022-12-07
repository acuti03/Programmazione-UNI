#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char cognome[31];
    char nome[31];
    char sesso;
    int annoNascita;
} Persona;


int main(){
    Persona p[100];
    FILE *f;
    char sesso[2];

    f = fopen("people.txt", "rt");
    if(f == NULL){
        printf("Errore nella lettura del file");
    }

    int i = 0;
    while(i < 100 && fscanf(f, "%s%s%s%d", p[i].cognome, p[i].nome, sesso, &p[i].annoNascita) == 4){
        p[i].sesso = sesso[1];
        printf("%s %s %c%d\n",p[i].cognome, p[i].nome, p[i].sesso, p[i].annoNascita );
        i++;
    }
    


    printf("\n");
    return 0;
}
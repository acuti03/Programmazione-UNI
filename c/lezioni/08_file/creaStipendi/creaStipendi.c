/*
    PER I FILE BINARI DEVO USARE FREAD E FWRITE
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[10];
    int stipendio;
} Dipendente;


int main(){
    Dipendente d[5] = {
        {"Simone", 1000},
        {"Maria", 0},
        {"Alessio", 2000},
        {"Hind", 5000},
        {"Alberti", 10000},
   };

    FILE *f;

    f = fopen("stipendi.dat", "wb");
    if(f == NULL){
        printf("Errore");
        exit(1);
    }

    fwrite(d, sizeof(d), 5, f);
    fclose(f);

    printf("\n");
    return 0;
}
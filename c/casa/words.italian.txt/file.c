#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
    int nRand;
    char stringa[31];
} parolaCasuale;


void rnd(parolaCasuale *p, int *a){
    p->nRand = rand()% *a + 1; 
}


void copia(parolaCasuale *p, char s[100000][31]){
    int j;

    for(j = 0; s[p->nRand][j] != '\0'; j++){
        p->stringa[j] = s[p->nRand][j];
    }
}

int main(){
    char stringhe[100000][31];
    char s[31];
    FILE *pf;
    parolaCasuale parola;
    srand(time(NULL)); 

    pf = fopen("words.italian.txt", "rt");
    if(pf == NULL){
        printf("Errore: file non trovato");
        exit(1);
    }

    int i = 0, j;
    while(fscanf(pf, "%s", s) == 1){
        for(j = 0; s[j] != '\0'; j++){
            stringhe[i][j] = s[j];
        }
        printf("%s\n", stringhe[i]);
        i++;
    }

    rnd(&parola, &i);
    copia(&parola, stringhe);

    printf("\n\nLa tua parola è: %s ed è all indice: %d", parola.stringa, parola.nRand);
    fclose(pf);

    printf("\n");
    return 0;
}
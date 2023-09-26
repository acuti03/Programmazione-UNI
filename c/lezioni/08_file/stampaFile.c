#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    FILE *fp;
    char nomeFile[20];
    char c;
    
    printf("\nInserisci il nome del file: ");
    scanf("%s", nomeFile);


    fp = fopen(nomeFile, "rt");

    if(fp == NULL){
        printf("\nErrore: il file %s non esiste!",nomeFile);
        exit(1);
    }

    while(fscanf(fp, "%c", &c) == 1){
        printf("%c", c);
    }
    

    if(fclose(fp) != 0){
        printf("\nErrore chiusura del file");
        exit(2);
    }



    printf("\n");
    return 0;
}
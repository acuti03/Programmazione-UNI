#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
    FILE *fp;
    char c;

    if(argc != 2){
        printf("Uso: %s nome_file_da_stampare\n", argv[0]);
        exit(3);
    }

    fp = fopen(argv[1], "rt");

    if(fp == NULL){
        printf("\nErrore: il file %s non esiste!",argv[1]);
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
#include "headers.h"


int main(int argc, char **argv){
    FILE *fb;
    FILE *ft; // parte 2
    Lista head;
    Record riga;
    Record righe[3];
    int i;


//  inizializzazioni e controlli
    system("clear");
    inizializza(&head);

    if(argc != 2){
        printf("\nErrore di usabilita...");
        exit(-1);
    }

    fb = fopen(argv[1], "rb");
    ft = fopen("ultimi3.txt", "w+t");

    if(fb == NULL){
        perror("\nErrore apertura file...");
        exit(-1);
    }

//  inserimento
    while(fread(&riga, sizeof(Record), 1, fb) > 0){
        aggiorna(&head, riga);
    }

//  stampa
    printf("\n\n--- LISTA ---\n\n");
    stampa(head);

//  parte 2
    fseek(fb, -sizeof(Record) * 3, SEEK_CUR);
    i = 0;
    while(fread(&riga, sizeof(Record), 1, fb) > 0){
        righe[i].durata = riga.durata;
        strcpy(righe[i].targa, riga.targa);
        i++;
    }


    for(i = 2; i >= 0; i--){
        fprintf(ft, "%s %0.2f\n", righe[i].targa, righe[i].durata);
    }


    fclose(ft);
    fclose(fb);
    printf("\n");
    return 0;
}
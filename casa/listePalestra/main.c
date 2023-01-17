#include "headers.h"


int main(int argc, char **argv){
    FILE *ft;
    FILE *fb;
    Lista head;
    Record riga;
    char cf[17];


//  inizializzazioni e controlli
    inizializza(&head);
    if(argc != 3){
        printf("\nErrore usabilita...\n");
        exit(EXIT_FAILURE);
    }

    fb = fopen(argv[1], "rb");
    ft = fopen(argv[2], "rt");

    if(ft == NULL || fb == NULL){
        printf("\nErrore lettura file...\n");
        exit(EXIT_FAILURE);
    }

//  inserimento nella lista
    while(fread(cf, sizeof(cf), 1, fb) > 0){
        inserisciCF(&head, cf);
    }

    printf("\n\n--- LISTA 1 ---\n\n");
    while(fscanf(ft, "%s %d", riga.cf, &riga.attivita) > 0){
        aggiorna(&head, riga);
    }

//  stampa tentativi falliti
    stampa(head);
    


    fclose(fb);
    fclose(ft);
    printf("\n");
    return EXIT_SUCCESS;
}
#include "headers.h"


int main(int argc, char **argv){
    FILE *ft;
    FILE *fb;
    Lista head;
    char CF[17];


//  controlli e inizializzazione dei file e della lista
    system("clear");
    inizializzaLista(&head);

    if(argc != 3){
        printf("\nErrore...\n");
        exit(1);
    }

    fb = fopen(argv[1], "rb");
    ft = fopen(argv[2], "rt");
    if(fb == NULL || ft == NULL){
        printf("\nErrore...\n");
        exit(1);
    }


//  riempimento della lista
    while(fread(CF, sizeof(CF), 1, fb) > 0){
        riempiLista(&head, CF);
    }
    printf("\n\n");
    stampa(head);


//  controllo e stampa
    controllo(&head, ft);
    printf("\n\n\n---- DOPO IL CONTROLLO ----\n\n");
    stampa(head);
    

    fclose(fb);
    fclose(ft);
    printf("\n");
    return 0;
}
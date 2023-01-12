#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    Record riga;


//  inizializzazione e controllo
    system("clear");
    if(argc != 2){
        printf("\nErrore utilizzo argomenti\n");
        exit(1);
    }

    inizializza(&head);
    f = fopen(argv[1], "rb");

    if(f == NULL){
        printf("\nErrore file\n");
        exit(1);
    }

//  aggiorna la lista
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        aggiorna(&head, riga);
    }

//  stampa
    printf("\n\n--- LISTA ---\n\n");
    stampa(head);

//  parte 2
    printf("\n\n--- LISTA 2 ---\n\n");
    elimina(&head);
    printf("\n");
    stampa(head);


    fclose(f);
    printf("\n");
    return 0;
}
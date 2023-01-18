#include "headers.h"


int main(int argc, char **argv){
    FILE *fb;
    FILE *ft; // file per la parte 2
    Lista head;
    Record riga;

    
//  inizializzazioni e controlli
    system("clear");
    inizializza(&head);

    if(argc != 2){
        printf("\nErrore utlizzo file...");
        exit(-1);
    }

    fb = fopen(argv[1], "rb");
    ft = fopen("vaccinati.txt", "w+t");

    if(fb == NULL || ft == NULL){
        printf("\nErrore apertura file...");
        exit(-1);
    }

//  aggiornamento lista e stampa
    while(fread(&riga, sizeof(Record), 1, fb) > 0){
        aggiorna(&head, riga);
    }
    printf("\n\n--- LISTA ---\n\n");
    stampa(head);

//  parte 2
    insertionSort(&head);
    inserimentoFile(head, ft);
    
    

    printf("\n");
    return 0;
}
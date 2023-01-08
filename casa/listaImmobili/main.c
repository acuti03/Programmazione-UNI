#include "headers.h"



int main(int argc, char **argv){
    FILE *fb;
    FILE *ft; // parte 2
    Lista head;
    Dato d;
    float n;


//  inserimenti e controlli
    system("clear");
    inizializza(&head);

    if(argc != 2){
        printf("\nErrore...\n");
        exit(1);
    }

    fb = fopen(argv[1], "rb");
    if(fb == NULL){
        printf("\nErrore...\n");
        exit(1);
    }
    
    ft = fopen("vani.txt", "w+t");
    if(ft == NULL){
        printf("\nErrore...\n");
        exit(1);
    }


//  inserimento nella lista
    while(fread(&d, sizeof(Dato), 1, fb) > 0){
        aggiorna(&head, d);
    }
    printf("\n\nLista:\n\n");
    stampa(head);

//  parte 2
    printf("\n\nInserisci un numero: ");
    scanf("%f", &n);
    printf("\n\nLista Ordinata:\n\n");
    ordina(&head, n);
    stampa(head);


    fclose(fb);
    fclose(ft);
    printf("\n");
    return 0;
}
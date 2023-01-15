#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    char parola[30];


//  inizializzazioni e controlli
    inizializza(&head);

    f = fopen(argv[1], "rt");

    if(f == NULL){
        printf("\nErrore apertura file...\n");
        exit(EXIT_FAILURE);
    }


//  aggiornamento lista e ordinamento
    while(fscanf(f, "%s", parola) > 0){
        for(int i = 0; parola[i] != '\0'; i++){
            if(parola[i] >= 'A' && parola[i] <= 'Z'){
                parola[i] = parola[i] + ('a' - 'A');
            }
        }
        aggiorna(&head, parola);
    }
    insertionSort(&head);

//  stampa
    stampa(head);

//  parte 2
    for(int i = 2; i < argc; i++){
        eliminaParola(&head, *(argv + i));
    }
    printf("\n\n--- LISTA 2: ---\n\n");
    stampa(head);

    fclose(f);
    printf("\n");
    return EXIT_SUCCESS;
}
#include "listaParole.h"

int main(int argc, char *argv[]){
    Lista l;
    FILE *f;
    int i;
    char parola[31];

    f = fopen(argv[1], "rt");
    nuovaLista(&l);

    if(f == NULL || argc < 2){
        printf("Errore...");
        exit(1);
    }

    while(fscanf(f, "%s", parola) == 1){
        for(i = 0; parola[i] != '\0'; i++){
            if(parola[i] >= 'A' && parola[i] <= 'Z'){
                parola[i] = parola[i] + 'a' - 'A'; 
            }
        }
        aggiora(&l, parola);
    }

    printf("\n\n-----STAMPA 1-----\n\n");
    stampa(l);
    fclose(f);

    for(i = 2; i < argc; i++){
        eliminaParola(&l, argv[i]);
    }

    printf("\n\n-----STAMPA 2-----\n\n");
    stampa(l);

    printf("\n");
    return 0;
}
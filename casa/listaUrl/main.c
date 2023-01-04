#include "listaUrl.h"


int main(){
    Lista head;
    Record riga;
    FILE *f;

//  inizializzazione della lista e del file
    inizializza(&head);
    f = fopen("visite.dat", "rb");
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        aggiorna(&head, riga);
    }

//  stampa parte 1
    printf("\n\n");
    for(int i = 0; i < 45; i++){ printf("-"); }
    printf("\nLista non ordinata:\n\n");
    printf("\n");
    stampa(head);
    for(int i = 0; i < 45; i++){ printf("-"); }

//  stampa parte 2
    ordinaLista(&head);
    printf("\n\n\n");
    for(int i = 0; i < 45; i++){ printf("-"); }
    printf("\nLista non ordinata:\n\n");
    printf("\n");
    stampa(head);
    for(int i = 0; i < 45; i++){ printf("-"); }

    printf("\n");
    return 0;
}
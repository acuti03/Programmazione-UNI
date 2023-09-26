#include "listaEsami.h"


int main(int argc, char *argv[]){
    Lista l;
    Record r;
    FILE *f;

    f = fopen(argv[1], "rb");
    nuovaLista(&l);

    while(fread(&r, sizeof(Record), 1, f) == 1){
        aggiorna(&l, r);
    }

    printf("\n\n");
    stampa(insertionSort(l));

    printf("\n");
    return 0;
}
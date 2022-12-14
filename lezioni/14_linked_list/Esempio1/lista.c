#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void azzera(Lista l){
    while (l){
        l->dato = 0;
        l = l->next;
    }
    
}
// non lo dichairo come puntatore perche lista è tipo puntarore
// in breve lo devo trattare come un array
void stampa(Lista l){
    while (l != NULL){
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n");
}

void listaNonOrdinata(Lista* pl, int n){
    // gli elementi da inserire nella lista
    int a[] = {6, 2, 3, 2, 4, 7, 0, 2, 5, 1};
    int i;
    // per i che va da 0 a n - 1
    for (i = 0; i < n; i++) {
        // *pl punta a un nuovo nodo
        (*pl) = (Nodo*)malloc(sizeof(Nodo));
        // il cui dato è a[i]
        (*pl)->dato = a[i];
        // e il cui campo next è NULL (cioè *pl ha un solo elemento; eventualmente
        // ne saranno aggiunti altri nelle iterazioni successive)
        (*pl)->next = NULL;
        // assegna a pl l'indirizzo della sua coda
        pl = &(*pl)->next;
    }
}
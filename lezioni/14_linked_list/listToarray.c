#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo{
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo *Lista;


//  FUNZIONE COPIATA (NON ANCORA INTRODOTTA DAL PROF)
void listaNonOrdinata(Lista* pl, int n) {
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

int lunghezzza(Lista l){
    int cnt = 0;

    while(l != NULL){
        cnt++;
        l = l->next;
    }
    return cnt;
}

int *lisToArray(Lista l){
    int dimensione;
    int *p;
    int i;

    dimensione = lunghezzza(l);

    p = (int *)malloc(dimensione * sizeof(int));

    if(p == NULL){
        printf("\nErrore");
    }

    i = 0;
    while (l != NULL){
        p[i] = l->dato;
        l = l->next;
        i++;
    }

    return p;
}

int main(){
    int *a;
    Lista l;
    
    listaNonOrdinata(&l, 6);
    int dimensione = lunghezzza(l);

    a = lisToArray(l);

    for(int i = 0; i < dimensione; i++){
        printf("%d ", a[i]); // *(a + i)
    }


    printf("\n\n");
    return 0;

}
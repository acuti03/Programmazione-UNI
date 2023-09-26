#include "lista.h"

int main(){
    Lista l;
    int n;

    creaLista(&l);

    do{
        scanf("%d", &n);
        if(n > 0 && (piena(l) == 0)){
            inserimentoOrdinato(&l, n);
        }
    } while (n > 0);
    
    stampa(l);
    
    printf("\n");
    return 0;
}
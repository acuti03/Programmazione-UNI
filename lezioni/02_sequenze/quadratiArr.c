/*
    SCRIVERE UN PROGRAMMA CHE INIZIALIZZI UN ARRAY DI 10 ELEMENTI
    AI QUADRATI DEI PRIMI 10 NUMERI NATURALI
*/

#include <stdio.h>


int main(){
    int i;

    for(i=1; i<=10; i++){
        printf("%d ", i * i);
    }
    return 0;
}

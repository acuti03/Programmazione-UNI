/*
    Leggere una serie di numeri interi passati dall’utente,
    fermandosi al primo numero che rende la serie non crescente 
    e restituendo quanti numeri erano stati inseriti.
*/

#include <stdio.h>

int main(){
    int n;
    int cnt = 0;
    int flag = 0;
    int min;
    
    do{
        if(cnt != 0) min = n;
        scanf("%d", &n);

        if(n < min && cnt != 0) flag = 1;
        cnt++;

    }while(flag == 0);

    printf("\nNumeri inseriti: %d", cnt);

    printf("\n");
    return 0;
}

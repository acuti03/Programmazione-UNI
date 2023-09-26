#include <stdio.h>

int main(){
    int n;
    int resto;
    int tmp;
    int cnt = 0;
    int i,j;
    int tmpPot;
    int somma = 0;

    scanf("%d", &n);

    tmp = n;
    while(tmp > 0){
        tmp = tmp / 10;
        cnt++;
    }

    printf("\nIl numero ha %d cifre\n",cnt);

    tmp = n;
    for(i=0; i < cnt; i++){
        resto = tmp % 10;
        tmp = tmp / 10;

        tmpPot = resto;
        for(j=1; j<cnt; j++){
            resto = resto * tmpPot;
        }
        somma = somma + resto;

    }
    if(somma == n){
        printf("\n%d è un numero di armstrong", n);
    }
}
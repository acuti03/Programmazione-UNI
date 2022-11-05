#include <stdio.h>

int main(){
    int n;
    int i, j;
    int tmp = 2;
    int somma = 0;
    
    printf("\nInserisci la lunghezza del tuo numero binario: ");
    scanf("%d",&n);

    int vet[n];

    printf("\nInserisci il tuo numero binario:\n");
    for(i=n-1; i>=0; i--){
        scanf("%d",&vet[i]);
    }

    for(i=n-1; i>=0; i--){
        if(vet[i] != 0){
            if(i == 0) tmp = 1;
            else{
                for(j=0; j<i-1; j++){
                    tmp = tmp * 2;
                }
            }
            somma = somma + tmp;
        }>P
        tmp = 2;
        printf("\ntmp: %d",tmp);
        printf("\nsomma: %d",somma);
    }

    printf("\n\nIl tuo numero in decimale è: %d", somma);

    return 0;
}
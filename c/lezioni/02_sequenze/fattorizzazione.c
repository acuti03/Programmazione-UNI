#include <stdio.h>

int primi(int n);

int main(){
    int n;
    int tmp;
    int fattore;

    printf("\nScrivi un numero: ");
    scanf("%d", &n);

    tmp = n;
    while (tmp > 1){
        fattore = primi(tmp);
        printf("\nIl fattore di %d è : %d", tmp, fattore);
        tmp = tmp / fattore;
        printf("\nOra n vale: %d\n", tmp);
    }
    
    return 0;    
}


int primi(int n){
    int i,j;
    int flag = 0;

    for(i=2; i<=n; i++){
        flag = 0;
        for(j=2; (j<=i/2) && (flag == 0); j++){
            if(i % j == 0) flag = 1;
        }
        if((flag == 0) && (n % i == 0)) return i;
    }
    return 0;
}

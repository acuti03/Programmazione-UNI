#include <stdio.h>

int somma(int n){
    if(n == 1){
        return 1;
    }
    return n + somma(n - 1);
}

int main(){
    int n = 100;

    printf("La somma: %d\n", somma(n));

    return 0;
}
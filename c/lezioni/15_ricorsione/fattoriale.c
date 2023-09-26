#include <stdio.h>

int fatt(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n * fatt(n - 1);
}

int main(){
    int n = 5;

    if(n >= 0) printf("%d\n", fatt(n));
    else printf("Errore...\n");

    return 0;
}
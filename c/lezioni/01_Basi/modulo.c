#include <stdio.h>

int main(){
    int n;

    scanf("%d", &n);

    printf("|%d| = %d", n, n > 0 ? n : -n);
    //printf("|%d| = %d", n, n < 0 ? -n : n);
}
#include <stdio.h>
#define DIM 10

int main(){
    int m;
    int a[DIM] = {0, 4, 5, 6, 8, -1, 11, 1, 2, 10};
    int i, j;

    for(i=0; i<DIM; i++){
        scanf("%d",a[i]);
        for(j=i; j > 0 && m > a[j-1]; j++){
            a[j] = a[j-1];
        }
        a[j] = m;
    }

    printf("\n\n");
    for(i=0; i < DIM; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
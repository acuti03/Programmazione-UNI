#include <stdio.h>
#include <stdlib.h>

int main(){
    int dim;
    int *a;
    int i;

    printf("Scrivi la dim: ");
    scanf("%d", &dim);
    a = (int *)malloc(sizeof(dim));

    for(i = 0; i < dim; i++){
        a[i] = i; // *(a + i) = i
        printf("%d ", a[i]);
    }

    free(a);

    printf("\n");
    return 0;
}
#include <stdio.h>
#define DIM 10

int main(){
    int a[DIM] = {0, 4, 5, 6, 8, -1, 11, 1, 2, 10};
    int i, j;
    int n;
    int min;
    int tmp;

    for(i=0; i < DIM; i++){
        min = i;
        for(j=i+1; j < DIM; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(i != min){
            tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }

    printf("\n");
    for(i=0; i<DIM; i++){
        printf("%d ", a[i]);
    }
    
    printf("\n");

    return 0;
}
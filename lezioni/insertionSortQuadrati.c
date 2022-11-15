#include <stdio.h>
#define DIM 10

int precede(int a, int b){
    return a * a < b * b;
}

int main(){
    int a[DIM] = {0, 4, 5, 6, 8, -1, 11, 1, 2, 10};
    int m;
    int i, j;

    for(i=0; i<DIM; i++){
        for(j=i, m=a[i]; j > 0 && precede(m, a[j-1]); j--){
            a[j] = a[j-1];
        }
        a[j] = m;
    }

    printf("\n");
    for(i=0; i < DIM; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

}
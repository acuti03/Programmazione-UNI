#include <stdio.h>
#define DIM 5

int main(void) {
    int m, a[DIM], dl, j;

    for (dl = 0; dl < DIM; dl++) {
        scanf("%d", &m);
        j = dl;
        while (j > 0 && a[j - 1] > m/* m precede a[j-1] secondo il criterio usato*/) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = m;
    }
  // l'array e` ordinato secondo il criterio usato

    for(dl = 0; dl < DIM; dl++){
        printf("%d ", a[dl]);
    }
}

#include <stdio.h>
#define DIM 5

int main(void) {
  int a[] = {4, 1, 8, 0, 5}, i, j;

  for (i = 0; i < DIM; i++) {
    int j = i, m = a[i];
    while (j > 0 && m < a[j - 1]) {
      a[j] = a[j - 1];
      j--;
    }
    a[j] = m;
  }
  
  for (i = 0; i < DIM; i++)
    printf("%d ", a[i]);
  printf("\n");
}
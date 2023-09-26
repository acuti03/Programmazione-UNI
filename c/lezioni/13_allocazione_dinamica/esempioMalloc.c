#include <stdio.h>
#include <stdlib.h>

int main(){
    double* p;
//  COME PARAMETRO CI DEVO METTERE LA DIMENSIONE DEL TIPO. QUINDI 4 BYTE = INT
    p = (double *)malloc(sizeof(double));
    scanf("%lf", p);
    printf("%lf\n", *p);
    free(p);

    return 0;
}
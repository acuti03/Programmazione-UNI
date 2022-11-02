#include <stdio.h>

int main(){
    float a,b,c;
    float ascisse[21], ordinate[21];
    int i;

    for(i=0; i<21; i++){
        ascisse[i] = ascisse[i] + 0.1 * i;
    }

    printf("\nInserire i coefficenti: ");
    scanf("%f%f%f",&a,&b,&c);

    for(i=0; i<21; i++){
        ordinate[i] = a * ascisse[1] + b * ascisse[i] + c * ascisse[i];
    }

    for(i=0; i<21; i++){
        printf("\n(%f, %f)", ascisse[i], ordinate[i]);
    }

    return 0;
}